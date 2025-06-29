SELECT
    ROUND(
        COUNT(*) * 1.0 / (SELECT COUNT(DISTINCT player_id) FROM Activity),
        2
    ) AS fraction
FROM (
    SELECT DISTINCT a.player_id
    FROM Activity a
    JOIN (
        SELECT player_id, MIN(event_date) AS first_login
        FROM Activity
        GROUP BY player_id
    ) b
    ON a.player_id = b.player_id
    WHERE a.event_date = DATE_ADD(b.first_login, INTERVAL 1 DAY)
) AS next_day_logins;
