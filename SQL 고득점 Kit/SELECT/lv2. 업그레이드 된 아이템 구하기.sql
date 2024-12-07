-- 코드를 작성해주세요
SELECT ITEM_INFO.ITEM_ID, ITEM_INFO.ITEM_NAME, ITEM_INFO.RARITY
FROM (
    SELECT ITEM_TREE.ITEM_ID
    FROM ITEM_INFO
    LEFT JOIN ITEM_TREE ON ITEM_INFO.ITEM_ID = ITEM_TREE.PARENT_ITEM_ID
    WHERE RARITY = "RARE"
    AND PARENT_ITEM_ID IS NOT NULL
) A
LEFT JOIN ITEM_INFO ON A.ITEM_ID = ITEM_INFO.ITEM_ID
ORDER BY ITEM_INFO.ITEM_ID DESC