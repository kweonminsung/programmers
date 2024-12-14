-- 코드를 작성해주세요
SELECT ITEM_INFO.ITEM_ID, ITEM_NAME
FROM ITEM_TREE
JOIN ITEM_INFO
ON ITEM_INFO.ITEM_ID = ITEM_TREE.ITEM_ID
WHERE PARENT_ITEM_ID IS NULL 
ORDER BY ITEM_ID ASC