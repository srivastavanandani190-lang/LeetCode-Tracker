# Write your MySQL query statement below
# Step 1: Get the latest change date on or before 2019-08-16 for each product
WITH LatestPriceBeforeDate AS (
    SELECT 
        product_id, 
        MAX(change_date) AS max_date
    FROM Products
    WHERE change_date <= '2019-08-16'
    GROUP BY product_id
),
# Step 2: Extract the price corresponding to that latest change date
ActualPrices AS (
    SELECT 
        p.product_id, 
        p.new_price AS price
    FROM Products p
    JOIN LatestPriceBeforeDate l 
      ON p.product_id = l.product_id 
     AND p.change_date = l.max_date
)
# Step 3: Combine all unique products and assign 10 to those with no prior changes
SELECT 
    u.product_id, 
    COALESCE(a.price, 10) AS price
FROM (SELECT DISTINCT product_id FROM Products) u
LEFT JOIN ActualPrices a 
  ON u.product_id = a.product_id;