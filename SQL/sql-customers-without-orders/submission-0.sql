-- Write your query below

select c.name as name from customers as c left join orders as o on c.id=o.customer_id where o.id is null;