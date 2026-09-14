# Write your MySQL query statement below
SELECT  e.name
FROM Employee e
JOIN Employee p
    ON e.id = p.managerId
GROUP BY e.name,e.id
HAVING COUNT(p.id) >= 5;