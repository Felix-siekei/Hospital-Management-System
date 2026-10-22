#include "repositories/MedicalRecordRepository.h"

bool MedicalRecordRepository::add(const MedicalRecord &record)
{
    if (findById(record.getId()) != nullptr)
    {
        return false;
    }

    records.push_back(record);
    return true;
}

MedicalRecord *MedicalRecordRepository::findById(int id)
{
    for (auto &record : records)
    {
        if (record.getId() == id)
        {
            return &record;
        }
    }

    return nullptr;
}

std::vector<MedicalRecord> MedicalRecordRepository::getAll() const
{
    return records;
}

std::vector<MedicalRecord> MedicalRecordRepository::findByPatientId(
    int patientId) const
{
    std::vector<MedicalRecord> patientRecords;

    for (const auto &record : records)
    {
        if (record.getPatientId() == patientId)
        {
            patientRecords.push_back(record);
        }
    }

    return patientRecords;
}

bool MedicalRecordRepository::update(const MedicalRecord &record)
{
    MedicalRecord *existing = findById(record.getId());

    if (existing == nullptr)
    {
        return false;
    }

    *existing = record;
    return true;
}

bool MedicalRecordRepository::remove(int id)
{
    for (auto it = records.begin(); it != records.end(); ++it)
    {
        if (it->getId() == id)
        {
            records.erase(it);
            return true;
        }
    }

    return false;
}