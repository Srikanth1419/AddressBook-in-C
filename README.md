# AddressBook-in-C
This Address Book project in C allows users to manage their contacts efficiently. It provides functionalities to add, search, edit, display, and save contacts in a structured manner. The contact details include Name, Mobile Number, and E-Mail ID.

1️ Add Contact:
The user can add a new contact to the phone directory.
Validation checks:
Ensures the mobile number is unique (removes duplicate contacts).
Validates the E-Mail ID format before storing.

2️ Search Contact:
The user can search for a contact using:
Name
Mobile Number
E-Mail ID
If found, the contact details are displayed; otherwise, it shows "Contact Not Found."

3️ Edit Contact:
Allows modification of existing contact details.
The process:
Search for the contact using Name, Number, or E-Mail.
If found, prompt the user to select which detail they want to edit (Name, Number, or E-Mail).
Validate the updated details before saving.
4️ Display Contacts
Shows a list of all saved contacts in the directory.
Displays details in a structured format for easy readability.

5️ Save Contacts:
Ensures contacts are not lost after exiting the program.
Saves the contact list to a CSV file (user-specified).
This allows users to reload contacts later when running the program again.

 Implementation Details
Uses file handling in C to store and retrieve contacts from a CSV file.
Implements data validation to ensure correct input formats.
Ensures duplicate handling to avoid multiple entries of the same contact.
The program runs in a menu-driven approach, making it user-friendly.
