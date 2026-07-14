# Write your MySQL query statement below
WITH DailyAmount AS (
    SELECT 
        visited_on,
        SUM(amount) AS amount
    FROM Customer
    GROUP BY visited_on
),
MovingStats AS (
    SELECT 
        visited_on,
        SUM(amount) OVER (
            ORDER BY visited_on 
            ROWS BETWEEN 6 PRECEDING AND CURRENT ROW
        ) AS amount,
        ROUND(AVG(amount) OVER (
            ORDER BY visited_on 
            ROWS BETWEEN 6 PRECEDING AND CURRENT ROW
        ), 2) AS average_amount,
        -- Generate a row number to easily skip the first 6 days
        ROW_NUMBER() OVER (ORDER BY visited_on) AS rn
    FROM DailyAmount
)
SELECT 
    visited_on,
    amount,
    average_amount
FROM MovingStats
WHERE rn >= 7
ORDER BY visited_on ASC;