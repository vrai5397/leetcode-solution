# Write your MySQL query statement below
select e.employee_id,e.name,count(*) as
reports_count,round(sum(p.age)/count(*),0) as average_age from Employees e join Employees p
on e.employee_id=p.reports_to group by employee_id
order by employee_id