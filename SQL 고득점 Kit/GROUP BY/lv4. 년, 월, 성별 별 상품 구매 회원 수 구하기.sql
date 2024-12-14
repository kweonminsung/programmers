-- 코드를 입력하세요
SELECT YEAR(SALES_DATE) AS YEAR, MONTH(SALES_DATE) AS MONTH, GENDER, COUNT(DISTINCT ONLINE_SALE.USER_ID) AS USERS
FROM ONLINE_SALE
JOIN USER_INFO
ON ONLINE_SALE.USER_ID = USER_INFO.USER_ID
WHERE GENDER IS NOT NULL
GROUP BY YEAR, MONTH, GENDER
ORDER BY YEAR ASC, MONTH ASC, GENDER ASC