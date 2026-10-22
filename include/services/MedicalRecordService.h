#pragma once

#include <vector>

#include "models/MedicalRecord.h"
#include "repositories/MedicalRecordRepository.h"

class MedicalRecordService
{
private:
    MedicalRecordRepository &repository;

public:
    explicit MedicalRecordService(MedicalRecordRepository &repository);

    bool createRecord(const MedicalRecord &record);
    MedicalRecord *findRecordById(int id);
    std::vector<MedicalRecord> getAllRecords() const;
    std::vector<MedicalRecord> getPatientMedicalHistory(int patientId) const;
    bool updateRecord(const MedicalRecord &record);
    bool removeRecord(int id);
};