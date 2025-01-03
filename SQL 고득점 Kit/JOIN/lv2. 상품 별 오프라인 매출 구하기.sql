-- 코드를 입력하세요
SELECT PRODUCT_CODE, SUM(PRICE * SALES_AMOUNT) AS SALES
FROM OFFLINE_SALE
JOIN PRODUCT
ON PRODUCT.PRODUCT_ID = OFFLINE_SALE.PRODUCT_ID
GROUP BY OFFLINE_SALE.PRODUCT_ID
ORDER BY SALES DESC, PRODUCT_CODE ASC