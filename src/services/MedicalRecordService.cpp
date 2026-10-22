#include "services/MedicalRecordService.h"

MedicalRecordService::MedicalRecordService(
    MedicalRecordRepository &repository)
    : repository(repository) {}

bool MedicalRecordService::createRecord(const MedicalRecord &record)
{
    if (record.getId() <= 0 ||
        record.getPatientId() <= 0 ||
        record.getDoctorId() <= 0 ||
        record.getDiagnosis().empty() ||
        record.getSymptoms().empty() ||
        record.getTreatment().empty() ||
        record.getRecordDate().empty())
    {
        return false;
    }

    return repository.add(record);
}

MedicalRecord *MedicalRecordService::findRecordById(int id)
{
    if (id <= 0)
    {
        return nullptr;
    }

    return repository.findById(id);
}

std::vector<MedicalRecord> MedicalRecordService::getAllRecords() const
{
    return repository.getAll();
}

std::vector<MedicalRecord>
MedicalRecordService::getPatientMedicalHistory(int patientId) const
{
    if (patientId <= 0)
    {
        return {};
    }

    return repository.findByPatientId(patientId);
}

bool MedicalRecordService::updateRecord(const MedicalRecord &record)
{
    if (record.getId() <= 0 ||
        record.getPatientId() <= 0 ||
        record.getDoctorId() <= 0 ||
        record.getDiagnosis().empty() ||
        record.getSymptoms().empty() ||
        record.getTreatment().empty() ||
        record.getRecordDate().empty())
    {
        return false;
    }

    return repository.update(record);
}

bool MedicalRecordService::removeRecord(int id)
{
    if (id <= 0)
    {
        return false;
    }

    return repository.remove(id);
}