-- 코드를 작성해주세요
SELECT YEAR(DIFFERENTIATION_DATE) AS YEAR,
    MAX(SIZE_OF_COLONY) OVER(PARTITION BY YEAR(DIFFERENTIATION_DATE)) - SIZE_OF_COLONY AS YEAR_DEV, ID
FROM ECOLI_DATA
ORDER BY YEAR ASC, YEAR_DEV ASC

-- GROUP BY를 통한 풀이
SELECT A.YEAR, MAX_SIZE - SIZE_OF_COLONY AS YEAR_DEV, ID
FROM ECOLI_DATA
LEFT JOIN (
    SELECT YEAR(DIFFERENTIATION_DATE) AS YEAR, MAX(SIZE_OF_COLONY) AS MAX_SIZE
    FROM ECOLI_DATA
    GROUP BY YEAR(DIFFERENTIATION_DATE)
) AS A
ON YEAR(ECOLI_DATA.DIFFERENTIATION_DATE) = A.YEAR
ORDER BY YEAR ASC, YEAR_DEV ASC