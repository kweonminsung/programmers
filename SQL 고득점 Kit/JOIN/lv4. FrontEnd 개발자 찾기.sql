-- 코드를 작성해주세요
SELECT ID, EMAIL, FIRST_NAME, LAST_NAME
FROM DEVELOPERS
CROSS JOIN (
    SELECT CODE
    FROM SKILLCODES
    WHERE CATEGORY = "Front End"
) AS A
ON A.CODE & DEVELOPERS.SKILL_CODE != 0
GROUP BY ID, EMAIL, FIRST_NAME, LAST_NAME
ORDER BY ID ASC