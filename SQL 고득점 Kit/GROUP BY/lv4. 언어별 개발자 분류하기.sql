-- 코드를 작성해주세요
SELECT IF(FE & PY, "A", IF(CS, "B", "C")) AS GRADE, ID, EMAIL
FROM (
    SELECT MAX(FE) AS FE, MAX(PY) AS PY, MAX(CS) AS CS, ID, EMAIL
    FROM (
        SELECT IF(CATEGORY = "Front End", 1, 0) AS FE, IF(SKILLCODES.NAME = "Python", 1, 0) AS PY, IF(SKILLCODES.NAME = "C#", 1, 0) AS CS, DEVELOPERS.ID, EMAIL
        FROM DEVELOPERS
        LEFT JOIN SKILLCODES
        ON DEVELOPERS.SKILL_CODE & SKILLCODES.CODE != 0
    ) AS A
    GROUP BY ID, EMAIL
) AS B
WHERE CS OR FE
ORDER BY GRADE ASC, ID ASC