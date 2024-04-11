WITH CTE AS (
    SELECT d.name AS Department, e.name AS Employee, e.salary AS Salary,
        DENSE_RANK() OVER (PARTITION BY e.departmentID ORDER BY e.salary DESC) AS salaryRank
    FROM Employee AS e JOIN Department d ON e.departmentId = d.id
)
SELECT Department, Employee, Salary FROM CTE WHERE salaryRank <= 3

-- SELECT d.name AS Department, e.name AS Employee, e.salary AS Salary
-- FROM Employee AS e, Department AS d
-- WHERE e.departmentId = d.id AND (
--     SELECT COUNT(DISTINCT e2.salary)
--     FROM Employee AS e2
--     WHERE e2.salary > e.salary AND e2.departmentId = e.departmentId
-- ) < 3