#include <iostream>
#include <string.h>
using namespace std;
int count_insertion_in_TrainClass=0;
int count_insertion_in_Train=0;
int count_insertion_in_TrainCapacity=0;
class TrianClass
{
    int cid; 
    char cname[20];
   public:
    void set_cid(int c)
    {
        cid = c;
    }
    void set_cname(char *cn)
    {
        strcpy(cname, cn);
    }
    int get_cid()
    {
        return cid;
    }
    char *get_cname()
    {
        return cname;
    }
    void display()
    {
        cout << "Cid  is " << cid << endl;
        cout << "Cname is " << cname << endl;
    }
};
class Train
{
    int tid; // unique
    char tname[20];
    char source[20];
    char destination[20];
    public:
    void set_tid(int t)
    {
        tid = t;
    }
    void set_tname(char *c)
    {
        strcpy(tname, c);
    }
    void set_source(char *s)
    {
        strcpy(source, s);
    }
    void set_destination(char *d)
    {
        strcpy(destination, d);
    }

    int get_tid()
    {
        return tid;
    }
    char *get_tname()
    {
        return tname;
    }
    char *get_source()
    {
        return source;
    }
    char *get_destination()
    {
        return destination;
    }
    void display()
    {
        cout << "Tid is " << tid << endl;
        cout << "Cname is " << tname << endl;
        cout << "Source is " << source << endl;
        cout << "Destination is " << destination << endl;
    }
};
class TrainCapacity
{
    int cid; // valid if present in array containing records of TrainClass
    int tid; // valid if present in array containing records of Train
    int totalSeats;
    int rate;
   public:
    void set_cid(int a)
    {
        cid = a;
    }
    void set_tid(int a)
    {
        tid = a;
    }
    void set_totalSeats(int a)
    {
        totalSeats = a;
    }
    void set_rate(int a)
    {
        rate = a;
    }
    int get_cid()
    {
        return cid;
    }
    int get_tid()
    {
        return tid;
    }
    int get_totalSeats()
    {
        return totalSeats;
    }
    int get_rate()
    {
        return rate;
    }
    void display()
    {
        cout << "Cid is " << cid << endl;
        cout << "Tid is " << tid << endl;
        cout << "Total Seats is " << totalSeats << endl;
        cout << "Rate is " << rate << endl;
    }
};
class Reservations
{
    int cid;
    int tid;
    // cid + tid valid if present in array containing records of TrainCapacity
    char Date[20]; // valid if given in the format dd/mm/yyyy
    int ticketNo;  // auto generated  on the basis of TrainCapacity:: totalSeats for a unique date if all the seats for that date for cid + tid are reserved them give the appropriate message.
                   // tid+cid+ticketno+date should be unique
    char CNIC[13];
    char passengerName[10]; // only alphabets allowed
    public:
    void set_cid(int c)
    {
        cid = c;
    }
    void set_tid(int t)
    {
        tid = t;
    }
    void set_Date(char *d)
    {
        strcpy(Date, d);
    }
    void set_ticketNO(int t)
    {
        ticketNo = t;
    }
    void set_CNIC(char *c)
    {
        strcpy(CNIC, c);
    }
    void set_passengerName(char *pn)
    {
        strcpy(passengerName, pn);
    }
    int get_cid()
    {
        return cid;
    }
    int get_tid()
    {
        return tid;
    }
    char *get_Date()
    {
        return Date;
    }
    int get_ticketNo()
    {
        return ticketNo;
    }
    char *get_CNIC()
    {
        return CNIC;
    }
    char *get_passengerName()
    {
        return passengerName;
    }

    void display()
    {
        cout << "Cid is " << cid;
        cout << "Tid is " << tid;
        cout << "Date is " << Date << endl;
        cout << "TicketNumber is " << ticketNo << endl;
        cout << "CNIC is " << CNIC << endl;
        cout << "Passenger Name is  " << passengerName << endl;
    }
};

void Function_TrianClass(TrianClass Trainclass[], TrainCapacity T_C[], int size_of_Trainclass)
{
    int check;
    int totaltrain = 0; // Track number of inserted records
    // Ensure at least one record is inserted before showing full menu
    while (totaltrain == 0)
    {
        cout << "\nNo records found! Please insert at least one record first." << endl;
        cout << "1. Insert Record\n";
        cout << "69. Exit\n";
        cout << "Enter your choice: ";
        cin >> check;
        if (check == 1)
        {
            if (totaltrain < size_of_Trainclass)
            {
                cout << "===== Insert Data into Train Class =====" << endl;
                int tempcid;
                char cname[20];

                cout << "Enter CID: ";
                cin >> tempcid;
                cin.ignore();
                cout << "Enter CName: ";
                cin.getline(cname, 20);

                Trainclass[totaltrain].set_cid(tempcid);
                Trainclass[totaltrain].set_cname(cname);
                totaltrain++;
                cout << "Record inserted successfully.\n";
            }
            else
            {
                cout << "Error: Cannot insert more records, array is full!\n";
            }
        }
        else if (check == 69)
        {
            cout << "Exiting program...\n";
            return;
        }
        else
        {
            cout << "Invalid choice! You must insert at least one record first.\n";
        }
    }
    // Main menu after inserting at least one record
    do
    {
        cout << "\n===== Train Class Menu =====" << endl;
        cout << "1. Update CName for a given CID" << endl;
        cout << "2. Delete a record for a given CID (only if it is not present in TrainCapacity array)" << endl;
        cout << "3. Display all TrainClass records" << endl;
        cout << "4. Display a record for a given CID" << endl;
        cout << "5. Insert Record" << endl;
        cout << "69. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> check;

        if (check == 1) // Update CName
        {
            int cid, found = 0;
            cout << "Enter CID to update CName: ";
            cin >> cid;

            for (int i = 0; i < totaltrain; i++)
            {
                if (cid == Trainclass[i].get_cid())
                {
                    cout << "Enter new CName: ";
                    char cname[20];
                    cin.ignore();
                    cin.getline(cname, 20);
                    Trainclass[i].set_cname(cname);
                    found = 1;
                    cout << "Record updated successfully.\n";
                    break;
                }
            }
            if (!found)
            {
                cout << "Error: No matching CID found!\n";
            }
        }
        else if (check == 2) // Delete record
        {
            int cid, found = 0;
            cout << "Enter CID to delete: ";
            cin >> cid;

            for (int i = 0; i < totaltrain; i++)
            {
                if (cid == T_C[i].get_cid())
                {
                    found = 1;
                    cout << "Error: CID is present in TrainCapacity. Cannot delete!\n";
                    break;
                }
            }

            if (!found)
            {
                for (int i = 0; i < totaltrain; i++)
                {
                    if (cid == Trainclass[i].get_cid())
                    {
                        for (int j = i; j < totaltrain - 1; j++) // Shift elements left
                        {
                            Trainclass[j] = Trainclass[j + 1];
                        }
                        totaltrain--;
                        cout << "Record deleted successfully. You can now insert more records.\n";
                        found = 1;
                        break;
                    }
                }
                if (!found)
                {
                    cout << "Error: No matching CID found!\n";
                }
            }
        }
        else if (check == 3) // Display all records
        {
            cout << "\n===== All TrainClass Records =====" << endl;
            if (totaltrain == 0)
            {
                cout << "No records to display.\n";
            }
            else
            {
                for (int i = 0; i < totaltrain; i++)
                {
                    Trainclass[i].display();
                }
            }
        }
        else if (check == 4) // Display specific record
        {
            int cid, found = 0;
            cout << "Enter CID to display details: ";
            cin >> cid;

            for (int i = 0; i < totaltrain; i++)
            {
                if (cid == Trainclass[i].get_cid())
                {
                    cout << "CID: " << Trainclass[i].get_cid() << endl;
                    cout << "CName: " << Trainclass[i].get_cname() << endl;
                    found = 1;
                    break;
                }
            }
            if (!found)
            {
                cout << "Error: No matching CID found!\n";
            }
        }
        else if (check == 5) // Insert new record
        {
            if (totaltrain >= size_of_Trainclass)
            {
                cout << "Error: Cannot insert more records, array is full!\n";
                continue;
            }

            cout << "===== Insert Data into Train Class =====" << endl;
            int tempcid;
            char cname[20];

            cout << "Enter CID: ";
            cin >> tempcid;
            cin.ignore();
            cout << "Enter CName: ";
            cin.getline(cname, 20);

            Trainclass[totaltrain].set_cid(tempcid);
            Trainclass[totaltrain].set_cname(cname);
            totaltrain++;
            cout << "Record inserted successfully.\n";
        }
        count_insertion_in_TrainClass++;

    } while (check != 69);
}
void Insertion_for_Reservation(Reservations R[], TrainCapacity T_C[], int &reservationCount, int size_of_Resefvation)
{
    cout << "Initializing reservation data entry..." << endl;
    cout << "Please enter the details for reservation insertion." << endl;

    int i = reservationCount; // Ensure we start from the correct index
    int totalSeats = 0;

    int c, tid;
    int chec4 = -1;
    // Get valid CID
    do
    {
        chec4 = -1;
        cout << "Enter Customer ID (CID): ";
        cin >> c;
        for (int j = 0; j < size_of_Resefvation; j++)
        {
            if (c == T_C[j].get_cid())
            {
                chec4 = 1;
                break;
            }
        }
        if (chec4 == 1)
        {
            R[i].set_cid(c);
        }
        else
        {
            cout << "Error: CID not found in TrainCapacity array. Please enter a valid CID." << endl;
        }
    } while (chec4 == -1);
    // Get valid TID
    do
    {
        chec4 = -1;
        cout << "Enter Train ID (TID): ";
        cin >> tid;
        for (int j = 0; j < size_of_Resefvation; j++)
        {
            if (tid == T_C[j].get_tid())
            {
                chec4 = 1;
                break;
            }
        }
        if (chec4 == 1)
        {
            R[i].set_tid(tid);
        }
        else
        {
            cout << "Error: TID not found in TrainCapacity array. Please enter a valid TID." << endl;
        }
    } while (chec4 == -1);
    // Determine total seats available for given CID & TID
    for (int j = 0; j < size_of_Resefvation; j++)
    {
        if (T_C[j].get_cid() == c && T_C[j].get_tid() == tid)
        {
            totalSeats = T_C[j].get_totalSeats();
            break;
        }
    }
    cin.ignore();
    cout << "Enter CNIC (13-digit number): ";
    char cnic[14];
    cin.getline(cnic, 14);
    R[i].set_CNIC(cnic);
    char psname[20];
    do
    {
        chec4 = 1;
        cout << "Enter Passenger Name: ";
        cin.getline(psname, 20);
        for (int j = 0; psname[j] != '\0'; j++)
        {
            if (!isalpha(psname[j]) && psname[j] != ' ')
            {
                chec4 = -1;
            }
        }
        if (chec4 == 1)
        {
            R[i].set_passengerName(psname);
        }
        else
        {
            cout << "Error: Name must contain only alphabets and spaces. Please re-enter the name." << endl;
        }
    } while (chec4 == -1);
    char date[11];
    bool validDate;
    do
    {
        validDate = true;
        cout << "Enter the date (Format: DD/MM/YYYY): ";
        cin.getline(date, 11);

        if (strlen(date) != 10 || date[2] != '/' || date[5] != '/')
        {
            cout << "Invalid format! Please enter the date in DD/MM/YYYY format." << endl;
            validDate = false;
        }
    } while (!validDate);

    R[i].set_Date(date);
    // Count current reservations for the given CID, TID, and Date
    int currentReservations = 0;
    for (int j = 0; j < reservationCount; j++)
    {
        if (R[j].get_tid() == tid && R[j].get_cid() == c && strcmp(R[j].get_Date(), date) == 0)
        {
            currentReservations++;
        }
    }
    // Check if all seats are reserved
    if (currentReservations >= totalSeats)
    {
        cout << "Error: All seats for this train, customer, and date are fully booked. Reservation not possible." << endl;
        return;
    }
    // Assign a unique ticket number
    int ticketNo = currentReservations + 1;
    R[i].set_ticketNO(ticketNo);

    // Increment reservation count after successful reservation
    reservationCount++;
    cout << "Reservation successfully added with Ticket No: " << ticketNo << endl;
}
void Function_Train(Train train[], TrainCapacity T_C[], int size_of_Train)
{
    int recordCount = 0; // Tracks the number of inserted records
    int number;
    do
    {
        // Ensure at least one record exists before allowing other operations
        if (recordCount == 0)
        {
            cout << "No records found! Please insert at least one record first.\n";
            cout << "1. Insert Record\n";
            cout << "69. Exit\n";
            cout << "Enter your choice: ";
            cin >> number;

            if (number != 1 && number != 69)
            {
                cout << "Invalid choice. Please insert at least one record first.\n";
                continue;
            }
        }
        else
        {
            cout << "\n==== Train Operations ====\n";
            cout << "Press 1 - Insert Record\n";
            cout << "Press 2 - Update train name for a given TID\n";
            cout << "Press 3 - Delete a record for a given TID (if not in TrainCapacity array)\n";
            cout << "Press 4 - Display all records\n";
            cout << "Press 5 - Display a record for a given TID\n";
            cout << "Press 69 - Exit the program\n";
            cout << "Enter your choice: ";
            cin >> number;
        }

        if (number == 1) // Insert Record
        {
            if (recordCount >= size_of_Train)
            {
                cout << "Sorry, the size of the array is full. No more insertions are allowed.\n";
            }
            else
            {
                cout << "===== Insert Data into Train =====" << endl;
                int tid, exists;

                do
                {
                    exists = 0;
                    cout << "Enter Train ID (TID): ";
                    cin >> tid;

                    for (int j = 0; j < recordCount; j++)
                    {
                        if (tid == train[j].get_tid())
                        {
                            exists = 1;
                            cout << "Error: TID already exists. Please enter a different ID.\n";
                        }
                    }
                } while (exists == 1);

                train[recordCount].set_tid(tid);

                cin.ignore();
                cout << "Enter Train Name: ";
                char tname[20];
                cin.getline(tname, 20);
                train[recordCount].set_tname(tname);

                cout << "Enter Source: ";
                char source[20];
                cin.getline(source, 20);
                train[recordCount].set_source(source);

                cout << "Enter Destination: ";
                char destination[20];
                cin.getline(destination, 20);
                train[recordCount].set_destination(destination);

                recordCount++; // Increase count after successful insertion
            }
        }
        else if (number == 2) // Update Train Name
        {
            if (recordCount == 0)
            {
                cout << "No records found! Please insert at least one record first.\n";
                continue;
            }

            int c = 0;
            cout << "Enter TID to update train name: ";
            int ci;
            cin >> ci;
            for (int i = 0; i < recordCount; i++)
            {
                if (ci == train[i].get_tid())
                {
                    cout << "Enter new train name: ";
                    char tnam[20];
                    cin.ignore();
                    cin.getline(tnam, 20);
                    train[i].set_tname(tnam);
                    c = 1;
                    cout << "Train name updated successfully.\n";
                }
            }
            if (c == 0)
            {
                cout << "No record found for the given TID.\n";
            }
        }
        else if (number == 3) // Delete a record
        {
            if (recordCount == 0)
            {
                cout << "No records found! Please insert at least one record first.\n";
                continue;
            }

            cout << "Enter TID to delete: ";
            int tid, check = 0;
            cin >> tid;

            for (int i = 0; i < recordCount; i++)
            {
                if (tid == T_C[i].get_tid())
                {
                    check = 1;
                    cout << "TID found in TrainCapacity array. Deletion not allowed.\n";
                    break;
                }
            }

            if (check == 0)
            {
                int indexToDelete = -1;
                for (int i = 0; i < recordCount; i++)
                {
                    if (tid == train[i].get_tid())
                    {
                        indexToDelete = i;
                        break;
                    }
                }

                if (indexToDelete != -1)
                {
                    for (int i = indexToDelete; i < recordCount - 1; i++)
                    {
                        train[i] = train[i + 1];
                    }
                    recordCount--;
                    cout << "Record deleted successfully.\n";
                }
                else
                {
                    cout << "No record found for the given TID.\n";
                }
            }
        }
        else if (number == 4) // Display All Records
        {
            if (recordCount == 0)
            {
                cout << "No records found! Please insert at least one record first.\n";
                continue;
            }

            cout << "Displaying all records in Train:\n";
            for (int i = 0; i < recordCount; i++)
            {
                train[i].display();
            }
        }
        else if (number == 5) // Display Specific Record
        {
            if (recordCount == 0)
            {
                cout << "No records found! Please insert at least one record first.\n";
                continue;
            }

            cout << "Enter TID to display record: ";
            int tid, found = 0;
            cin >> tid;

            for (int i = 0; i < recordCount; i++)
            {
                if (tid == train[i].get_tid())
                {
                    cout << "TID: " << train[i].get_tid() << "\n";
                    cout << "Train Name: " << train[i].get_tname() << "\n";
                    cout << "Source: " << train[i].get_source() << "\n";
                    cout << "Destination: " << train[i].get_destination() << "\n";
                    found = 1;
                    break;
                }
            }
            if (!found)
            {
                cout << "No record found for the given TID.\n";
            }
        }
        count_insertion_in_Train++;
    } while (number != 69);
}
void Function_TrainCapacity(TrainCapacity T_C[], Reservations R[], Train train[], TrianClass Trainclass[], int size_of_Train_Capacity)
{
    if (count_insertion_in_TrainClass == 0 && count_insertion_in_Train == 0 )
    {
        cout<<"Sorry you cannot enter perform  First go to TrainClass and Train  and fill atlest 1 insertion in these classes "<<endl;
        return;
    }
        if (count_insertion_in_TrainClass == 0)
        {
            cout << "Sorry You cannot perform operatoins First go and fill atlest 1 inseration in TrainClass " << endl;
            return;
        }
    if(count_insertion_in_Train ==0){
        cout << "Sorry You cannot perform operatoins First go and fill atlest 1 inseration in Train" << endl;
        return;
    }
        int number;
    int traincapacity = size_of_Train_Capacity;
    int recordCount = 0; // Track the number of inserted records
    do
    {
        if (recordCount == 0)
        {
            cout << "No records found! Please insert at least one record first." << endl;
            cout << "1. Insert Record\n";
            cout << "69. Exit\n";
            cout << "Enter your choice: ";
            cin >> number;

            if (number == 1)
            {
                if (recordCount < size_of_Train_Capacity)
                {
                    cout << "===== Insert Data into Train Capacity =====" << endl;
                    int tempTid, tempCid;
                    int validCid = 0, validTid = 0;

                    do
                    {
                        cout << "Enter Customer ID (CID): ";
                        cin >> tempCid;
                        for (int i = 0; i < size_of_Train_Capacity; i++)
                        {
                            if (tempCid == Trainclass[i].get_cid())
                            {
                                validCid = 1;
                                break;
                            }
                        }
                        if (!validCid)
                            cout << "Error: CID not found in TrainClass array. Please enter a valid CID." << endl;
                    } while (!validCid);

                    do
                    {
                        cout << "Enter Train ID (TID): ";
                        cin >> tempTid;
                        for (int i = 0; i < size_of_Train_Capacity; i++)
                        {
                            if (tempTid == train[i].get_tid())
                            {
                                validTid = 1;
                                break;
                            }
                        }
                        if (!validTid)
                            cout << "Error: TID not found in Train array. Please enter a valid TID." << endl;
                    } while (!validTid);

                    T_C[recordCount].set_cid(tempCid);
                    T_C[recordCount].set_tid(tempTid);

                    cout << "Enter Total Seats available: ";
                    int ts;
                    cin >> ts;
                    T_C[recordCount].set_totalSeats(ts);

                    cout << "Enter Fare Rate: ";
                    int r;
                    cin >> r;
                    T_C[recordCount].set_rate(r);

                    cout << "Record inserted successfully." << endl;
                    recordCount++;
                }
                else
                {
                    cout << "Error: Cannot insert more records, array is full!" << endl;
                }
            }
            else if (number == 69)
            {
                break;
            }
            continue;
        }
        cout << "Press 1 - Update attributes (excluding TID and CID) for a given TID and CID" << endl;
        cout << "Press 2 - Delete a record for a given TID and CID if it is not present in the Reservations array" << endl;
        cout << "Press 3 - Display all records in the TrainCapacity array" << endl;
        cout << "Press 4 - Display a record for a given TID and CID" << endl;
        cout << "5.Inseration   ";
        cout << "Press 69 - Exit the program" << endl;
        
        cout << "Enter your choice: ";
        cin >> number;
        if (number == 1)
        {
            int c = 0;
            cout << "Enter CID: ";
            int ci;
            cin >> ci;
            for (int i = 0; i < traincapacity; i++)
            {
                if (ci == T_C[i].get_cid())
                {
                    cout << "Enter TID: ";
                    int ti;
                    cin>>ti;
                    if(ti == T_C[i].get_tid()){
                        cout << "Enter total seats: ";
                        int ts;
                        cin >> ts;
                        T_C[i].set_totalSeats(ts);
                        c = 1;
                        cout << "Enter rate: ";
                        cin>>ts;
                        T_C[i].set_rate(ts);
                        cout<<"Record Updates successfully "<<endl;
                        c=1;
                    } 
                    if(c ==0){
                        cout << "No matching TID found for the given CID." << endl;
                        c=-1;
                    }     
                }
            }
            if (c == 0)
            {
                cout << "No matching CID found." << endl;
            }
        }
        else if(number ==2){
            cout << "Enter CID: ";
            int c;
            int t;
            int check = 0;
            cin >> c;
            cout << "Enter TID: ";
            cin >> t;
            for (int i = 0; i < traincapacity; i++)
            {
                if (c == R[i].get_cid())
                {
                    
                    if(t==R[i].get_tid()){
                        check = 1;
                        cout << "TID and CID found in the Reservations array." << endl;
                    }
                    
                }
            }
            if (check == 0)
            {  int chec=0;
                for (int i = 0; i < traincapacity; i++)
                {
                    if (c == T_C[i].get_cid())
                    {  
                        if(t == T_C[i].get_tid()){
                            T_C[i]=T_C[i+1];
                            chec=1;
                            traincapacity--;
                                    cout<< "Record deleted successfully." << endl;
                                    recordCount--;
                        }

                       
                    }
                }
                if(chec ==0){
                    cout << "No matching record found for the given TID and CID." << endl;
                }
            }
        }
        else if(number ==3){
            cout << "Displaying all records in TrainCapacity:" << endl;
            int a=0;
            for (int i = 0; i < recordCount; i++)
            {
                T_C[i].display();
                a++;
            }
            if(a==0){
                cout<<"No record is their "<<endl;
            }
        }
        else if(number ==4){
            int c = 0;
            cout << "Enter CID: ";
            int ci;
            cin >> ci;
            for (int i = 0; i < traincapacity; i++)
            {
                if (ci == T_C[i].get_cid())
                {
                    cout << "Enter TID: ";
                    int ti;
                    cin >> ti;
                    if (ti == T_C[i].get_tid())
                    {
                        T_C[i].display();
                        c = 1;
                    }
                    if (c == 0)
                    {
                        cout << "No matching TID found for the given CID." << endl;
                        c=-1;
                    }
                }
            }
            if (c == 0)
            {
                cout << "No matching CID found." << endl;
            }
        }
        else if(number ==5){
            cout << "Initializing Train Capacity data entry..." << endl;
            cout << "Please enter the details for train capacity insertion." << endl;
            int tempt, tempc;
            int chec3 = -1;

            for (int i = 0; i < traincapacity; i++)
            {
                do
                {
                    chec3 = -1;
                    cout << "Enter Customer ID (CID): ";
                    cin >> tempc;
                    for (int i = 0; i < traincapacity; i++)
                    {
                        if (tempc == Trainclass[i].get_cid())
                        {
                            chec3 = 1;
                        }
                    }
                    if (chec3 == 1)
                    {
                        T_C[i].set_cid(tempc);
                    }
                    if (chec3 == -1)
                    {
                        cout << "Error: CID not found in TrainClass array. Please enter a valid CID." << endl;
                    }

                } while (chec3 == -1);

                do
                {
                    chec3 = -1;
                    cout << "Enter Train ID (TID): ";
                    cin >> tempt;
                    for (int i = 0; i < traincapacity; i++)
                    {
                        if (tempt == train[i].get_tid())
                        {
                            chec3 = 1;
                        }
                    }
                    if (chec3 == 1)
                    {
                        T_C[i].set_tid(tempt);
                    }
                    if (chec3 == -1)
                    {
                        cout << "Error: TID not found in Train array. Please enter a valid TID." << endl;
                    }
                } while (chec3 == -1);

                cout << "Enter Total Seats available: ";
                int ts;
                cin >> ts;
                T_C[i].set_totalSeats(ts);

                cout << "Enter Fare Rate: ";
                int r;
                cin >> r;
                T_C[i].set_rate(r);
                cout << "Train Capacity entry successfully added." << endl;
            
            }
        }
         count_insertion_in_TrainCapacity ++;

    } while (number != 69);
}
void Function_Reservations(Reservations R[], int &reservationCount, TrainCapacity T_C[], int size_of_Resefvation)
{
    int number;
    int total = size_of_Resefvation;

    if (count_insertion_in_TrainCapacity==0){
        cout<<"First Go to TrainCapacity Class and insert some record "<<endl;
        return;
    }
        if (reservationCount == 0)
        {
            cout << "No records found! Please insert at least one reservation first." << endl;
            Insertion_for_Reservation(R, T_C, reservationCount, size_of_Resefvation);
            total++;
        }
    do
    {
        
        cout << "1 - Update reservation details (excluding TID, CID, Ticket Number, and Date)" << endl;
        cout << "2 - Delete a reservation using TID, CID, Ticket Number, and Date" << endl;
        cout << "3 - View all reservations" << endl;
        cout << "4 - Search for a reservation by TID, CID, and Date" << endl;
        cout << "5 - Check total available seats for a given TID, CID, and Date" << endl;
        cout << "6.Inseration  "<<endl;
        cout << "69 - Exit the program" << endl;
        cout << "Enter your choice: ";
        cin >> number;

        if (number == 1)
        {
            int tid, cid, ticketNo;
            char date[11];
            cout << "Enter TID: ";
            cin >> tid;
            cout << "Enter CID: ";
            cin >> cid;
            cout << "Enter Ticket Number: ";
            cin >> ticketNo;
            cin.ignore();
            cout << "Enter Date (dd/mm/yyyy): ";
            cin.getline(date, 11);

            bool found = false;
            for (int i = 0; i < reservationCount; i++)
            {
                if (R[i].get_tid() == tid && R[i].get_cid() == cid && R[i].get_ticketNo() == ticketNo && strcmp(R[i].get_Date(), date) == 0)
                {
                    cout << "Enter new Passenger Name: ";
                    char name[20];
                    cin.getline(name, 20);
                    R[i].set_passengerName(name);

                    cout << "Enter new CNIC: ";
                    char cnic[13];
                    cin.getline(cnic, 13);
                    R[i].set_CNIC(cnic);

                    found = true;
                    cout << "Reservation updated successfully!" << endl;
                    break;
                }
            }
            if (!found)
                cout << "No matching reservation found." << endl;
        }

        else if (number == 2)
        {
            int tid, cid, ticketNo;
            char date[11];
            cout << "Enter TID: ";
            cin >> tid;
            cout << "Enter CID: ";
            cin >> cid;
            cout << "Enter Ticket Number: ";
            cin >> ticketNo;
            cin.ignore();
            cout << "Enter Date (dd/mm/yyyy): ";
            cin.getline(date, 11);

            bool found = false;
            for (int i = 0; i < reservationCount; i++)
            {
                if (R[i].get_tid() == tid && R[i].get_cid() == cid && R[i].get_ticketNo() == ticketNo && strcmp(R[i].get_Date(), date) == 0)
                {
                    for (int j = i; j < reservationCount - 1; j++)
                    {
                        R[j] = R[j + 1]; // Shift reservations left
                    }
                    reservationCount--; // Decrease total count
                    found = true;
                    cout << "Reservation deleted successfully!" << endl;
                    total--;
                     break;
                }
            }
            if (!found)
                cout << "No matching reservation found." << endl;
        }

        else if (number == 3)
        {
            if (reservationCount == 0)
            {
                cout << "No reservations available." << endl;
            }
            else
            {
                cout << "--- All Reservations ---" << endl;
                for (int i = 0; i < reservationCount; i++)
                {
                    cout << "TID: " << R[i].get_tid() << ", CID: " << R[i].get_cid()
                    << ", Ticket No: " << R[i].get_ticketNo() << ", Date: " << R[i].get_Date()
                         << ", Passenger Name: " << R[i].get_passengerName() << ", CNIC: " << R[i].get_CNIC() << "\n";
                }
            }
        }

        else if (number == 4)
        {
            int tid, cid;
            char date[11];
            cout << "Enter TID: ";
            cin >> tid;
            cout << "Enter CID: ";
            cin >> cid;
            cin.ignore();
            cout << "Enter Date (dd/mm/yyyy): ";
            cin.getline(date, 11);

            cout << "--- Reservation Details ---" << endl;
            bool found = false;
            for (int i = 0; i < reservationCount; i++)
            {
                if (R[i].get_tid() == tid && R[i].get_cid() == cid && strcmp(R[i].get_Date(), date) == 0)
                {
                    cout << "TID: " << R[i].get_tid() << ", CID: " << R[i].get_cid()
                         << ", Ticket No: " << R[i].get_ticketNo() << ", Passenger Name: " << R[i].get_passengerName()
                         << ", CNIC: " << R[i].get_CNIC() << "\n";
                    found = true;
                }
            }
            if (!found)
                cout << "No matching reservation found." << endl;
        }

        else if (number == 5)
        {
            int tid, cid;
            char date[11];
            cout << "Enter TID: ";
            cin >> tid;
            cout << "Enter CID: ";
            cin >> cid;
            cin.ignore();
            cout << "Enter Date (dd/mm/yyyy): ";
            cin.getline(date, 11);

            int count = 0;
            for (int i = 0; i < reservationCount; i++)
            {
                if (R[i].get_tid() == tid && R[i].get_cid() == cid && strcmp(R[i].get_Date(), date) == 0)
                {
                    count++;
                }
            }
            cout << "Total seats reserved for TID: " << tid << ", CID: " << cid << " on " << date << " = " << count << endl;
        }
        else if(number ==6){
            Insertion_for_Reservation(R, T_C, reservationCount,size_of_Resefvation);
        }

    } while (number != 69);
}
int main()
{

   int size_of_Trainclass;
   int choice;
   cout << "Enter the size of record that you enter in TrainClass ";
   cin >> size_of_Trainclass;
   TrianClass Trainclass[size_of_Trainclass];
   cout << "Enter the size of record that you enter in TrainClass ";
   int size_of_Train;
   cin >>size_of_Train;
   Train train[size_of_Train];
   cout << "Enter the size of record that you enter in TrainCapacity ";
   int size_of_Train_Capacity;
   cin>>size_of_Train_Capacity;
   TrainCapacity T_C[size_of_Train_Capacity];
   cout <<"Enter the size of record that you enter in Reservation ";
   int size_of_Resefvation;
   cin>>size_of_Resefvation;
   int reservationCount = 0; // Initialize reservation count
   Reservations R[size_of_Resefvation];
   do
   {
       cout << "========= Train Management System =========" << endl;
       cout << "1. Manage Train Classes" << endl;
       cout << "2. Manage Trains" << endl;
       cout << "3. Manage Train Capacity" << endl;
       cout << "4. Manage Reservations" << endl;
       cout << "69. Exit" << endl;
       cout << "Enter your choice: ";
       cin >> choice;

       if (choice == 1)
       {
           cout << "=== Train Class Operations ====" << endl;
           Function_TrianClass(Trainclass, T_C, size_of_Trainclass);
       }
       else if (choice == 2)
       {
           cout << "==== Train Operations ====" << endl;
           Function_Train(train, T_C, size_of_Train);
       }
       else if (choice == 3)
       {
           cout << "==== Train Capacity Operations ====" << endl;
           Function_TrainCapacity(T_C, R, train, Trainclass, size_of_Train_Capacity);
       }
       else if (choice == 4)
       {
           cout << "==== Reservation Operations ====" << endl;
           Function_Reservations(R, reservationCount, T_C,size_of_Resefvation);
       }
       else if (choice == 69)
       {
           cout << "Exiting the system... Thank you!" << endl;
       }
       else
       {
           cout << "Invalid choice! Please enter a valid option." << endl;
       }
    } while (choice != 69);
    return 0;
}
