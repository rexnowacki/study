// Christopher Nowacki | CIS 278
// Assignment #3 -- Hardware Store Inventory Management

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

// This function determines if the data file "hardware.dat" exists 
// and returns that information to determine if the file should be
// intialized. 

bool check_file(const string& filename) {
  ifstream ifile;
  ifile.open(filename);
  if(ifile) {
    cout << filename << " is valid.\n";
    ifile.close();
    return true; 
  } else {
    cout << "File doesn't exist.\n";
    return false;
  }
}
// Checks if a tool with the given ID in "hardware.dat" exists 
bool tool_exists(int id) {
  ifstream file("hardware.dat", ios::binary);
  if (!file) {
    return false;
  }
  // Determine position and move to it
  streampos pos = id * (sizeof(int) + 20 + sizeof(int) + sizeof(double));
  file.seekg(pos);

  int existing_id = 0;
  file.read(reinterpret_cast<char*>(&existing_id), sizeof(int));
  file.close();
  // Check if a tool exists with the ID
  // Should be 0 for non-existing tools
  return existing_id != 0;
}
// Intializes "hardware.dat" with 100 blank records
void initHardwareData(const string& filename) {
  ofstream file(filename, ios::binary);
  // Check if file can be opened, quit on failure
  if (!file) {
    cout << "Could not create file." << endl;
    exit(EXIT_FAILURE);
  }
  
  // Initialize variables for default values
  int id = 0;
  char tool_name[20] = {'\0'};
  int quantity = 0;
  double cost = 0;

  // Loop to write 100 blank records
  // Should create a 2800 byte file
  for (int i = 0; i < 100; ++i) {
    // Write ID number, name, quantity, cost
    file.write(reinterpret_cast<const char*>(&id), sizeof(int));
    file.write(tool_name, 20); // Write 20 bytes (max char length of tool)
    file.write(reinterpret_cast<const char*>(&quantity), sizeof(int));
    file.write(reinterpret_cast<const char*>(&cost), sizeof(double));
  }
  file.close();
}

// List all tools
void list_all_tools() {
  // Oopen the file in read mode
  ifstream file("hardware.dat", ios::binary);;

  // Error checking
  if (!file) {
    cout << "Failed to open file." << endl;
    return;
  }

  int id, quantity;
  double cost;
  char tool_name[20];
  bool records_found = false; // For checking if records were found

  cout << "ID #  \tTool Name\tQuantity\t   Cost\n";
  cout << "--------------------------------------------------\n";

  // Read and display each record
  while (file.read(reinterpret_cast<char*>(&id), sizeof(int))) {
    file.read(tool_name, 20);
    file.read(reinterpret_cast<char*>(&quantity), sizeof(int));
    file.read(reinterpret_cast<char*>(&cost), sizeof(double));
    if (id != 0) { // Skip empty records on display
      cout << setw(2) << id << setw(20) << tool_name << setw(7) << quantity
      << setw(20) << fixed << setprecision(2) << cost << endl;
    records_found = true;
    } 
  }

  file.close();

  // Display message if no records found
  if (!records_found) {
    cout << "No records found." << endl << endl;
  }
}

// Add tool
void add_tool(int id, const string& name, int quantity, double cost) {
  fstream file("hardware.dat", ios::in | ios::out | ios::binary);

  if (!file) {
    cout << "Failed to open file." << endl;
    return;
  }

  // Ensure that user enters valid ID number
  if (id < 0 || id >= 100) {
    cout << "Invalid ID number. Must be betwixt 0 and 99." << endl;
    return ;
  }

  // Calculate the position where to write the data based on the ID
  streampos pos = id * (sizeof(int) + 20 + sizeof(int) + sizeof(double)); // What.
  
  string tool_name(name);
  tool_name.resize(20, '\0'); // truncate or pad the string 
  
  // Seek to the position and write data
  file.seekp(pos);
  file.write(reinterpret_cast<const char*>(&id), sizeof(int));
  file.write(tool_name.c_str(), 20);
  file.write(reinterpret_cast<const char*>(&quantity), sizeof(int));
  file.write(reinterpret_cast<const char*>(&cost), sizeof(double));

  file.close();
}

// Edit Tool
void edit_tool(int id) {
  fstream file("hardware.dat", ios::in | ios::out | ios::binary);

  if (!file) {
    cout << "Failed to open file." << endl;
    return ;
  }

  if (id < 0 || id >=100) {
    cout << "Invalid ID number. Must be betwixt 0 and 99." << endl;
    return;
  }

  // Calculate the position where to read/write the data based on ID
  streampos pos = id * (sizeof(int) + 20 + sizeof(int) + sizeof(double));

  // Seek to the position
  file.seekg(pos);

  int existing_id;
  char existing_tool_name[20];
  int existing_quantity;
  double existing_cost;

  // Read existing data
  file.read(reinterpret_cast<char*>(&existing_id), sizeof(int));
  file.read(existing_tool_name, 20);
  file.read(reinterpret_cast<char*>(&existing_quantity), sizeof(int));
  file.read(reinterpret_cast<char*>(&existing_cost), sizeof(double));

  if (existing_id == 0) {
    cout << "No tool exists with that ID." << endl;
    return;
  }

  // Display old id, toolname, etc for reference
  cout << "Editing tool with ID " << existing_id << endl;
  cout << "Existing Name: " << existing_tool_name << endl;
  cout << "Existing Quantity: " << existing_quantity << endl;
  cout << "Existing Cold: " << existing_cost << endl;

  string new_name;
  int new_quantity;
  double new_cost;

  cout << "Enter new Tool Name: ";
  getline(cin >> ws, new_name); 
  cout << "Enter new quantity: ";
  cin >> new_quantity;
  cout << "Enter new cost: ";
  cin >> new_cost;

  // Prepare the new name, make it only 20 bytes
  string new_tool_name(new_name);
  new_tool_name.resize(20, '\0'); // truncate or pad the string 
  
  // Seek back to the position
  file.seekp(pos);

  // Write new data
  file.write(reinterpret_cast<const char*>(&existing_id), sizeof(int));
  file.write(new_tool_name.c_str(), 20);
  file.write(reinterpret_cast<const char*>(&new_quantity), sizeof(int));
  file.write(reinterpret_cast<const char*>(&new_cost), sizeof(double));

  file.close();
}

// Delete Tool
void delete_tool(int id) {
  fstream file("hardware.dat", ios::in | ios::out | ios::binary);

  if (!file) {
    cout << "Failed to open file." << endl;
    return;
  }

  if (id < 0 || id >= 100) {
    cout << "Invalid ID number. Must be betwixt 0 and 99." << endl;
  return;
  }

  // Calculate the position where to write the data based on the ID
  streampos pos = id * (sizeof(int) + 20 + sizeof(int) + sizeof(double));

  // Create a string to hold the name and intialize other fields to zero
  int zero_id = 0; // Previously declared as argument
  string tool_name(20, '\0');
  int quantity = 0;
  double cost = 0;

  // Seek to the position
  file.seekp(pos);

  // Write the data
  file.write(reinterpret_cast<const char*>(&zero_id), sizeof(int));
  file.write(tool_name.c_str(), 20);
  file.write(reinterpret_cast<const char*>(&quantity), sizeof(int));
  file.write(reinterpret_cast<const char*>(&cost), sizeof(double));

  file.close();
}


int main(){
  if (!check_file("hardware.dat")) {
    cout << "Initializing hardware.dat..." << endl;
    initHardwareData("hardware.dat");
  }
  
  int choice, id, quantity;
  double cost;
  string tool_name;
  while (true) { // Infinite loop to keep program running until exit
  cout << "1: List tools" << endl;
  cout << "2: Add tools" << endl;
  cout << "3: Edit tools" << endl; // Still need to implement
  cout << "4: Delete tools" << endl;
  cout << "5: Quit" << endl;
  cout << "Enter choice: ";
  cin >> choice;

  switch (choice) {
    case 1:
      list_all_tools();
      break;
    case 2:
      cout << "Enter Tool ID (0-99): ";
      cin >> id;
      if (tool_exists(id)) {
        cout << "Tool with this ID already exists. Please use the edit function" << endl;
        cout << "to edit an existing tool, or enter a unique ID number." << endl;
        break;
      }
      cout << "Enter Tool Name: ";
      cin >> ws;
      getline(cin, tool_name);
      cout << "Enter Tool Quantity: ";
      cin >> quantity;
      cout << "Enter Tool Cost: ";
      cin >> cost;
      add_tool(id, tool_name, quantity, cost);
      break;
    case 3:
      cout << "Enter Tool ID to edit (0-99): ";
      cin >> id;
      edit_tool(id);
      break;
    case 4:
      cout << "Enter Tool ID (0-99) to delete: ";
      cin >> id;
      delete_tool(id);
      break;
    case 5:
      cout << "Goodbye." << endl;
      return 0;
    default:
      cout << "Invalid choice." << endl;
  }
  }
  return 0;
}
