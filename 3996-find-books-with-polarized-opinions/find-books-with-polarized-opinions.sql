SELECT
    b.book_id,
    b.title,
    b.author,
    b.genre,
    b.pages,
    (MAX(rs.session_rating) - MIN(rs.session_rating)) AS rating_spread,
    ROUND(
        SUM(CASE WHEN rs.session_rating <= 2 OR rs.session_rating >= 4 THEN 1 ELSE 0 END) 
        / COUNT(rs.session_id), 
        2
    ) AS polarization_score
FROM books b
JOIN reading_sessions rs 
    ON b.book_id = rs.book_id
GROUP BY
    b.book_id, b.title, b.author, b.genre, b.pages
HAVING
    COUNT(rs.session_id) >= 5                                   -- at least 5 sessions
    AND MAX(rs.session_rating) >= 4                              -- at least one high rating
    AND MIN(rs.session_rating) <= 2                              -- at least one low rating
    AND (
        SUM(CASE WHEN rs.session_rating <= 2 OR rs.session_rating >= 4 THEN 1 ELSE 0 END) 
        / COUNT(rs.session_id)
    ) >= 0.6                                                     -- polarization score filter
ORDER BY 
    polarization_score DESC,
    title DESC;
