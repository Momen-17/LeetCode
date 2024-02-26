SELECT unique_id, name
FROM Employees em
LEFT JOIN EmployeeUNI emu
    ON em.id = emu.id