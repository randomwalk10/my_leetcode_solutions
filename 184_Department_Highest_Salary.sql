# Write your MySQL query statement below
# first join two tables on department id
# then filter rows that matches with highest salary within department.

SELECT D.Name As Department, E.Name As Employee, E.Salary As Salary
FROM Employee As E 
INNER JOIN Department As D ON E.DepartmentId = D.Id
WHERE
    (E.DepartmentId, E.Salary) in (
    SELECT E.DepartmentId, MAX(E.Salary)                        
    FROM Employee as E
    GROUP BY E.DepartmentId)
