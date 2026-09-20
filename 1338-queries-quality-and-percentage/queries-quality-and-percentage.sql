# Write your MySQL query statement below
select query_name,
round(sum(rating/position)/count(*),2) as quality,
round(count(if(rating<3,1,NULL))*100/count(*),2) as poor_query_percentage 
from  Queries
group by query_name