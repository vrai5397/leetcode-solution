# Write your MySQL query statement below
select date_format(trans_date,'%Y-%m') as month,
country,count(if(country='NULL',1,1)) as trans_count,count(if(state='approved',1,NULL)) as approved_count,sum(amount) as trans_total_amount,SUM(IF(state = 'approved', amount, 0)) AS approved_total_amount
from Transactions group by month,country
