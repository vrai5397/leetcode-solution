# Write your MySQL query statement below
WITH temp AS (
    SELECT 
        customer_id,
        MIN(order_date) AS first_order
    FROM Delivery
    GROUP BY customer_id
)

SELECT 
    ROUND(
        SUM(d.order_date = d.customer_pref_delivery_date) * 100.0
        / COUNT(*),
        2
    ) AS immediate_percentage
FROM Delivery d
INNER JOIN temp t
    ON d.customer_id = t.customer_id
WHERE d.order_date = t.first_order;