-- 코드를 입력하세요
SELECT APNT_NO, PT_NAME, APPOINTMENT.PT_NO, APPOINTMENT.MCDP_CD, DR_NAME, APPOINTMENT.APNT_YMD
FROM APPOINTMENT
JOIN DOCTOR
ON DOCTOR.DR_ID = APPOINTMENT.MDDR_ID
JOIN PATIENT
ON PATIENT.PT_NO = APPOINTMENT.PT_NO
WHERE DATE(APNT_YMD) = DATE("2022-04-13")
 AND APNT_CNCL_YN != "Y"
ORDER BY APPOINTMENT.APNT_YMD ASC