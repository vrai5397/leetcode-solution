# Write your MySQL query statement below
select * ,
case 
when x+y>z
and y+z>x
and z+x>y
then 'Yes'
else 'No'
END AS triangle
from Triangle