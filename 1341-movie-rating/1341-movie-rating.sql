# Write your MySQL query statement below
(
    -- Part 1: Top User
    SELECT u.name AS results
    FROM Users u
    JOIN MovieRating r ON u.user_id = r.user_id
    GROUP BY u.user_id, u.name
    ORDER BY COUNT(r.movie_id) DESC, u.name ASC
    LIMIT 1
)
UNION ALL
(
    -- Part 2: Top Movie in February 2020
    SELECT m.title AS results
    FROM Movies m
    JOIN MovieRating r ON m.movie_id = r.movie_id
    WHERE r.created_at >= '2020-02-01' AND r.created_at <= '2020-02-29'
    GROUP BY m.movie_id, m.title
    ORDER BY AVG(r.rating) DESC, m.title ASC
    LIMIT 1
);