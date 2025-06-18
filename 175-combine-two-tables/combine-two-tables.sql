# Write your MySQL query statement below
select Person.firstName,Person.lastName,Address.city,Address.state from Address RIGHT JOIN Person ON Person.personId= Address.personId; 