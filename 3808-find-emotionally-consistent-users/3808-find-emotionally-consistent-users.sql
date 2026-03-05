WITH reaction_counts AS (
    SELECT 
        user_id,
        reaction,
        COUNT(*) AS cnt
    FROM reactions
    GROUP BY user_id, reaction
),
total_counts AS (
    SELECT 
        user_id,
        COUNT(*) AS total_reactions
    FROM reactions
    GROUP BY user_id
),
ranked AS (
    SELECT 
        rc.user_id,
        rc.reaction,
        rc.cnt,
        tc.total_reactions,
        ROW_NUMBER() OVER (PARTITION BY rc.user_id ORDER BY rc.cnt DESC) AS rn
    FROM reaction_counts rc
    JOIN total_counts tc
    ON rc.user_id = tc.user_id
)

SELECT 
    user_id,
    reaction AS dominant_reaction,
    ROUND(cnt * 1.0 / total_reactions, 2) AS reaction_ratio
FROM ranked
WHERE rn = 1
AND total_reactions >= 5
AND (cnt * 1.0 / total_reactions) >= 0.6
ORDER BY reaction_ratio DESC, user_id ASC;