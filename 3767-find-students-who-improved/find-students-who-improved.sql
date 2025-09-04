SELECT 
  d.student_id,
  d.subject,
  s_first.score  AS first_score,
  s_last.score   AS latest_score
FROM (
  SELECT 
    student_id, 
    subject,
    MIN(exam_date) AS first_date,
    MAX(exam_date) AS last_date,
    COUNT(*)       AS cnt
  FROM Scores
  GROUP BY student_id, subject
) AS d
JOIN Scores AS s_first
  ON s_first.student_id = d.student_id
 AND s_first.subject    = d.subject
 AND s_first.exam_date  = d.first_date
JOIN Scores AS s_last
  ON s_last.student_id = d.student_id
 AND s_last.subject    = d.subject
 AND s_last.exam_date  = d.last_date
WHERE d.cnt >= 2
  AND s_last.score > s_first.score
ORDER BY d.student_id, d.subject;
