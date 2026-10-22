#pragma once

#include <vector>

#include "models/MedicalRecord.h"

class MedicalRecordRepository
{
private:
    std::vector<MedicalRecord> records;

public:
    bool add(const MedicalRecord &record);
    MedicalRecord *findById(int id);
    std::vector<MedicalRecord> getAll() const;
    std::vector<MedicalRecord> findByPatientId(int patientId) const;
    bool update(const MedicalRecord &record);
    bool remove(int id);
};