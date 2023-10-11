## Part I

## Part II

Using the DFDs for primary care assignment...

# a. Create two USE CASES. Use one of them to create a USE CASE DIAGRAM.

1. Schedule an Appointment
  Actor: **Patient**, *Admin*
  Preconditions: 
               * The doctor's schedule is open.
               * Patient's records are accessible to the admin.
  Postconditions:
               * Appointment is scheduled and both the patient and doctor have details of appt.
  Description: A patient wishes to schedule an appointment with a doctor. The patient can either
               call the office and the admin will schedule it, or the patient can use the online
               portal to book it.
  Steps:
    1.1. Patient contacts the office or accesses the online portal.
    1.2. Patient provides desired date and time or selects from available slots.
    1.3. Administration checks doctor's availability.
    1.4. Appointment is scheduled.
    1.5. Patient received a confirmation.
  Alternate Flow: Desired Date/Slot Not Available
    1.3.1. During step 1.3., admin finds doctor has no open appointments available.
    1.3.2. Admin offers alternate provider.
    1.3.3. Patient selects a new slot or does not move forward with booking.
    1.3.4. If new slot is selected, proceed to step 1.4 of the basic flow.
  Exceptions:
               * If the system or online portal malfunctions, patient will be advised
                 to contact later or use another method of booking.
               * If the doctor is on an extended leave, admin might suggest scheduling
                 with an alternate physician.

2. Update Medical Information
  Actor: **Patient**, *Admin*
  Preconditions:
               * Patient has an account within the system. 
  Postconditions: 
               * Medical information is up-to-date.
  Description: Patient's medical profile is out-of-date, and needs to be updated. Patient can
               log-in and update through a portal, or could fill out updated information at their
               next in office visit via pen and paper, which will be manually updated by admin.
  Steps:
    1.1. Patient comes into the office for a visit or logs into the portal.
    1.2. Patient updates and saves medical history and billing details.
    1.3. Notification of update is sent to administration.
    1.4. Administration reviews the changes and confirms updated details in the system.
Exceptions:
             * If the online system malfunctions, admin will encourage patient to update
               the information at their next visit or try again later.

<insert use_case_diagram.jpg>


