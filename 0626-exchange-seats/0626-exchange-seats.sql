# Write your MySQL query statement below
SELECT 
    CASE 
        -- If the ID is odd and it is the last seat, keep it the same
        WHEN MOD(id, 2) = 1 AND id = (SELECT COUNT(*) FROM Seat) THEN id
        -- If the ID is odd and not the last seat, increment it by 1
        WHEN MOD(id, 2) = 1 THEN id + 1
        -- If the ID is even, decrement it by 1
        ELSE id - 1
    END AS id,
    student
FROM Seat
ORDER BY id ASC;