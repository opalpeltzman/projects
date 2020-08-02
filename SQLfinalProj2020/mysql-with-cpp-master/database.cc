/*
 * ===================================================================
 *
 *       Filename:  database.cc
 *
 *    Description:  Definition of MySQL Class for accessing database
 *
 *        Created:  Friday 22 February 2013 02:07:49  IST
 *       Compiler:  gcc
 *
 *         Author:  Mandeep Kaur, meghasimak@gmail.com
 *        License:  GNU General Public License
 *      Copyright:  Copyright (c) 2013, Great Developers
 *
 * ===================================================================
 */

/**-------------------------------------------------------------------
 *  Include mysql.h file local header file(declaration of class)
 *------------------------------------------------------------------*/

#include "database.h"

/**
 *--------------------------------------------------------------------
 *       Class:  MySQL
 *      Method:  MySQL :: MySQL()
 * Description:  Constructor to initialize database conectivity
 *--------------------------------------------------------------------
 */

MySQL :: MySQL()
{
    connect = mysql_init(NULL);
    if ( !connect )
    {
        std::cout << "MySQL Initialization Failed";
    }   

    connect = mysql_real_connect(connect, SERVER, USER, PASSWORD, DATABASE, 0,NULL,0);
    
    if ( connect )
    {
        std::cout << "Connection Succeeded\n";
    }
    
    else
    {
        std::cout << "Connection Failed\n";
    }
}

/**
 *--------------------------------------------------------------------
 *       Class:  MySQL
 *      Method:  MySQL :: ShowTables()
 * Description:  Show tables in database
 *--------------------------------------------------------------------
 */

void MySQL :: ShowTables()
{
    /** Add MySQL Query */
    mysql_query(connect, "show tables");
    
                                                                          
    i = 0; 
                                                                         
    res_set = mysql_store_result(connect);                              
                                                                          
    unsigned int numrows = mysql_num_rows(res_set);                   
                                                                          
    std::cout << " Tables in " << DATABASE << " database " << endl;        
                                                                         
    while (((row=mysql_fetch_row(res_set)) != NULL))
    {                                                                 
        std::cout << row[0]<< endl;
    }

    system("pause"); system("cls");;
}

/**
 *--------------------------------------------------------------------
 *       Class:  MySQL
 *      Method:  MySQL :: ~MySQL()
 * Description:  Destructor of MySQL class for closing mysql
 *               connection
 *--------------------------------------------------------------------
 */

MySQL :: ~MySQL()
{
    mysql_close (connect);
}


void MySQL::owner()
{
    bool run = true;
    bool flag = false;
    int pick = 0;
    while (run)
    {
        if (flag)
        {
            system("cls");
            std::cout << "invalid pick , try again." << endl << endl;
        }

        cout << "1: check if a book is in inventory" << endl;
        cout << "2: check who is the oldest customer" << endl;
        cout << "3: check what is the oldest book in stock" << endl;
        cout << "4: get current orders list" << endl;
        cout << "5: check amount of books sold for a specific book" << endl;
        cout << "6: Find the most read author between dates" << endl;
        cout << "7: Find top 3 customers according to their purchases" << endl;
        cout << "8: check which book has the biggest amount of translators" << endl;
        cout << "9: Show purchases history of a customer" << endl;
        cout << "10: Show orders history of customer" << endl;
        cout << "11: calculate shipping cost" << endl;
        cout << "12: check if a customer splitted a purchase to two deliveries" << endl;
        cout << "13: check the current status of a delivery" << endl;
        cout << "14: check the total cost of shippings made by Xpress" << endl;
        cout << "15: check the total sum of money transfered to the store by Bit" << endl;
        cout << "16: Find all transactions with cost above the average cost in the last year" << endl;
        cout << "17: check the number of deliveries made by Xpress and Israel post in the last year" << endl;
        cout << "18: check details about all deliveries that include 2 or more editions of the same book" << endl;
        cout << "19: Find all customers that haven't purchased at the last 24 months" << endl;
        cout << "20: Find all customers that there book order has arrived and didn't arrive to take their books for at least 14 days" << endl;
        cout << "21: check the number of books in storage" << endl;
        cout << "22: check the number of books the store purchased and the total price paid between two dates" << endl;
        cout << "23: check the store profit in a given month" << endl;
        cout << "24: check the annual average in monthly transactions" << endl;
        cout << "25: check an employee salary " << endl;
        cout << "26: check who is the employee with most transactions" << endl;
        cout << "0: Exit" << endl;
        cin >> pick;
        cin.ignore(INT_MAX, '\n');
        flag = false;
        std::system("cls");

        switch (pick)
        {
        case 1:q1(); break;
        case 2:q2(); break;
        case 3:q3(); break;
        case 4:q4(); break;
        case 5:q5(); break;
        case 6:q6(); break;
        case 7:q7(); break;
        case 8:q8(); break;
        case 9:q9(); break;
        case 10:q10(); break;
        case 11:q11(); break;
        case 12:q12(); break;
        case 13:q13(); break;
        case 14:q14(); break;
        case 15:q15(); break;
        case 16:q16(); break;
        case 17:q17(); break;
        case 18:q18(); break;
        case 19:q19(); break;
        case 20:q20(); break;
        case 21:q21(); break;
        case 22:q22a(); break;
        case 23:q22b(); break;
        case 24:q23(); break;
        case 25:q24(); break;
        case 26:q25(); break;
        case 0:return; break;
        default:
            flag = true;
            break;
        }
    }
}

void MySQL::worker()
{
    bool run = true;
    bool flag = false;
    int pick = 0;
    while (run)
    {
        if (flag)
        {
            system("cls");
            std::cout << "invalid pick , try again." << endl << endl;
        }

        cout << "1: check if a book is in inventory" << endl;
        cout << "2: check who is the oldest customer" << endl;
        cout << "3: check what is the oldest book in stock" << endl;
        cout << "4: get current orders list" << endl;
        cout << "5: Find the most read author between dates" << endl;     
        cout << "6: check which book has the biggest amount of translators" << endl;
        cout << "7: Show purchases history of a customer" << endl;
        cout << "8: Show orders history of customer" << endl;
        cout << "9: calculate shipping cost" << endl;
        cout << "10: check if a customer splitted a purchase to two deliveries" << endl;
        cout << "11: check the current status of a delivery" << endl;
        cout << "12: check the number of deliveries made by Xpress and Israel post in the last year" << endl;
        cout << "13: check details about all deliveries that include 2 or more editions of the same book" << endl;
        cout << "14: Find all customers that there book order has arrived and didn't arrive to take their books for at least 14 days" << endl;
        cout << "15: check the number of books in storage" << endl;
        cout << "0: Exit" << endl;
        cin >> pick;
        cin.ignore(INT_MAX, '\n');
        flag = false;
        std::system("cls");

        switch (pick)
        {
        case 1:q1(); break;
        case 2:q2(); break;
        case 3:q3(); break;
        case 4:q4(); break;
        case 5:q6(); break;
        case 6:q8(); break;
        case 7:q9(); break;
        case 8:q10(); break;
        case 9:q11(); break;
        case 10:q12(); break;
        case 11:q13(); break;
        case 12:q17(); break;
        case 13:q18(); break;
        case 14:q20(); break;
        case 15:q21(); break;
        case 0:return; break;
        default:
            flag = true;
            break;
        }
    }
}


void MySQL::mainMenu()
{
    int pick = 0;
    string password = "sqlforlife";
    string password1;

    while (1)
    {
        std::cout << "hello! welcome to your second hand book store" << endl;
        cout << "please choose your position:" << endl << "1. shop owner" << endl << "2. shop worker" << endl;
        cin >> pick;
        cin.ignore(INT_MAX, '\n');

        if (pick == 1)
        {
            system("cls");
            cout << "please enter your password:" << endl;
            cin >> password1;
            cin.ignore(INT_MAX, '\n');
            if (password == password1)
            {
                owner();
                return;
            }
            else
            {
                system("cls");
                cout << "invalid password." << endl;
            }
        }
        else if (pick == 2)
        {
            worker();
            return;
        }
        else if (pick != 1 && pick != 2 )
        {
            std::system("cls");
            std::cout << "invalid pick, please try again." << endl;
        }   
    }
}

char* MySQL::stringTochar(string str)
{
    char* temp = new char[str.length() + 1];
    strcpy(temp, str.c_str());
    return temp;
}

void splitStr(vector<string>& strings, char str[])
{
    char* token = strtok(str, "-,\n");

    for (int i = 0; token != NULL; i++)
    {
        strings.push_back(token);
        token = strtok(NULL, "-,\n");
    }
}

void splitStrSpace(vector<string>& strings, char str[])
{
    char* token = strtok(str, " \n");

    for (int i = 0; token != NULL; i++)
    {
        strings.push_back(token);
        token = strtok(NULL, " \n");
    }
}

void MySQL::q1()
{
    string query1 = "SELECT location from book where group_id in(select group_id from book_group_id where book_name ='";
    string query2 = "');";
    string user;
    char buff[50] = { 0 };
    std::cout << "what book would you like to search?"<<endl;
    fgets(buff, 100, stdin);
    buff[strlen(buff) - 1] = 0;
    user = buff;
    user.shrink_to_fit();

    query1 = query1 + user + query2;
    char* final = stringTochar(query1);

    /** Add MySQL Query */
    mysql_query(connect, final);
    delete final;

    res_set = mysql_store_result(connect);

    if (res_set->row_count == 0)
    {
       
        system("cls");
        cout << "no such book in store" << endl;
        system("pause");
        system("cls");
        return;
    }

    if (res_set->row_count != 0)
    {
        row = mysql_fetch_row(res_set);
        std::cout << "the book is in stock and is located at "<<row[0] << endl;
    }

    system("pause");
    system("cls");
}

void MySQL::q2()
{
    string query1 = "select costumer_id, f_name, l_name, join_date from costumers where join_date = (select min(join_date) from costumers);";

    char* final = stringTochar(query1);

    /** Add MySQL Query */
    mysql_query(connect, final);
    delete final;

    res_set = mysql_store_result(connect);



    if (res_set->row_count != 0)
    {
        row = mysql_fetch_row(res_set);
        std::cout << "costumer id | " << "full name | " << "date joined" << endl;
        std::cout << row[0] <<" | "<< row[1] <<" "<< row[2]<<" | "<< row[3] << endl;
    }

    system("pause");
    system("cls");
}

void MySQL::q3()
{
    string query1 = "select book_name from book_group_id where group_id in(select group_id from book where book_sn in(select book_sn from purchases_books inner join purchases on(select purch_num from purchases where purch_date = (select min(purch_date) from purchases) and purchases.purch_num = purchases_books.purch_num)));";
    char* final = stringTochar(query1);

    /** Add MySQL Query */
    mysql_query(connect, final);
    delete final;


    res_set = mysql_store_result(connect);

    if (res_set != nullptr && res_set->row_count != 0)
    {
        row = mysql_fetch_row(res_set);
        std::cout << "the oldest book in the store is: " << row[0] << endl;
    }

    system("pause");
    system("cls");
}

void MySQL::q4()
{
    string query1 = "select o.order_num, o.costumer_id, book_name, o_status, order_date\
        from orders o\
        inner join costumer_orders co on o.order_num = co.order_num\
        order by contact_date desc;";

    char* final = stringTochar(query1);

    mysql_query(connect, final);
    delete final;

    res_set = mysql_store_result(connect);

    if (res_set != nullptr && res_set->row_count != 0)
    {
        std::cout << "order number | " << "costumer ID | " << "book name | " << "status | " << "order date" << endl;
        while (((row = mysql_fetch_row(res_set)) != NULL))
            std::cout<< row[0] << " | " << row[1] << " | " << row[2] << " | " << row[3] << " | " << row[4] << endl;

    }

    system("pause");
    system("cls");
}

void MySQL::q5()
{
    
    string query1 = "SELECT		count(*) FROM 		book_group_id JOIN	transaction_group_id ON book_group_id.group_id = transaction_group_id.group_id where 		book_name = '";
    string user;
    string query2 = "';";

    char buff[100] = { 0 };
    std::cout << "what book would you like to check?" << endl;
    fgets(buff, 100, stdin);
    buff[strlen(buff) - 1] = 0;
    user = buff;
    user.shrink_to_fit();

    query1 = query1 + user + query2;
    char* final = stringTochar(query1);
    mysql_query(connect, final);
    delete final;

    res_set = mysql_store_result(connect);
   



    if (res_set != nullptr && res_set->row_count != 0)
    {
         row = mysql_fetch_row(res_set);
         if (*row[0] == '0')
         {
             system("cls");
             cout << "no such book in store" << endl;
             system("pause");
             system("cls");
             return;
         }
        std::cout << "the amount of copies of book " << user << " sold by the store is: " << row[0] << endl;
    }

    system("pause");
    system("cls");
}

void MySQL::q6()
{
    string query1 = "select author from book_authors where book_sn in(\
                    select book_sn from book where group_id in(\
                        select group_id\
                        from transactions\
                        join transaction_group_id\
                        on transactions.transaction_id = transaction_group_id.transaction_id\
                where t_date between '";
    string user2;
    string query3 = "' and '";
    string query5 = "')) limit 1;";
    string user4;

    bool bad = true;

    while (bad)
    {
        std::cout << "please enter start date in format yyyy-mm-dd seperated with comma sign" << endl;
        cin >> user2;
        if (user2[4] != '-' || user2[7] != '-')
        {
            system("cls");
            cout << "invalid input, try again" << endl << endl;
            bad = true;
        }
        else
            bad = false;
    }
    bad = true;

    while (bad)
    {
        std::cout << "please enter end date in format yyyy-mm-dd seperated with comma sign" << endl;
        cin >> user4;
        if (user4[4] != '-' || user4[7] != '-')
        {
            system("cls");
            cout << "invalid input, try again" << endl << endl;
            bad = true;
        }
        else
            bad = false;
    }

    query1 = query1 + user2 + query3 + user4 + query5;
    char* final = stringTochar(query1);

    mysql_query(connect, final);
    delete final;

    res_set = mysql_store_result(connect);

    if (res_set->row_count == 0)
    {

        system("cls");
        cout << "no books were sold bettween these dates - no author is most read." << endl;
        system("pause");
        system("cls");
        return;
    }

    if (res_set->row_count != 0)
    {
        row = mysql_fetch_row(res_set);
        std::cout << "most readed author is: "<< row[0] <<endl;
    }

    system("pause");
    system("cls");
}

void MySQL::q7()
{
    string query1 = "select f_name, l_name, subquery.costumer_id from(select costumer_id, count(costumer_id) as freqvalue from transactions group by costumer_id order by freqvalue desc limit 3) as subquery join costumers on  subquery.costumer_id = costumers.costumer_id;";

    char* final = stringTochar(query1);

    mysql_query(connect, final);
    delete final;

    res_set = mysql_store_result(connect);

    if (res_set != nullptr && res_set->row_count != 0)
    {
        std::cout << "full name\t" << "costumer ID\t" << endl << endl;
        while (((row = mysql_fetch_row(res_set)) != NULL))
            std::cout << row[0] << " " << row[1] << "\t" << row[2] << endl;

    }

    system("pause");
    system("cls");
}

void MySQL::q8()
{
    string query1 = "select*, count(book_name) from(\
                    select translator, book_name, group_id from book_group_id\
                    ) as secondsubquery\
                    group by book_name\
                    order by count(book_name) desc\
                    limit 1;";

    char* final = stringTochar(query1);

    mysql_query(connect, final);
    delete final;

    res_set = mysql_store_result(connect);

    if (res_set != nullptr && res_set->row_count != 0)
    {
        std::cout << "book name | " << "amount of copies | " << endl;
        while (((row = mysql_fetch_row(res_set)) != NULL))
            std::cout << row[0] << " | " << row[1]  << endl;

    }

    system("pause");
    system("cls");
}

void MySQL::q9()
{
    string query1 = "select f_name, l_name, book_name, t_date, transaction_cost\
                        from(\
                            select transaction_cost, f_name, l_name, t_date, group_id\
                            from(\
                                select transaction_cost, f_name, l_name, t_date, transaction_id\
                                from(\
                                    select costumer_id, f_name, l_name\
                                    from costumers\
                        where costumer_id = '";
    string user;
    string query2 = "') as subquery\
                        join transactions\
                           on subquery.costumer_id = transactions.costumer_id) as secondsub\
                        join transaction_group_id\
                          on secondsub.transaction_id = transaction_group_id.transaction_id) as thirdsub\
                        join book_group_id\
                          on thirdsub.group_id = book_group_id.group_id\
                        order by t_date desc;";

    std::cout << "enter the costumer id you would like to check?" << endl;
    cin >> user;
    cin.ignore(INT_MAX, '\n');

    query1 = query1 + user + query2;
    char* final = stringTochar(query1);
    mysql_query(connect, final);
    delete final;

    res_set = mysql_store_result(connect);

    if (res_set->row_count == 0)
    {

        system("cls");
        cout << "there is no costumer with that id in store" << endl;
        system("pause");
        system("cls");
        return;
    }

    if (res_set != nullptr && res_set->row_count != 0)
    {
        std::cout <<"book name | " << "transaction date | " <<"transaction cost" << endl;
        while (((row = mysql_fetch_row(res_set)) != NULL))
            std::cout << row[2] << " | "<< row[3] << " | " << row[4] << endl;

    }


    system("pause");
    system("cls");
}

void MySQL::q10()
{
    string query1 = "select f_name, l_name, costumer_orders.costumer_id, book_name, o_status, costumer_orders.order_num, contact_date, order_date\
                    from(\
                        select f_name, l_name, orders.costumer_id, book_name, o_status, order_num, contact_date\
                        from(\
                            select f_name, l_name, costumer_id\
                            from costumers\
                    where costumer_id = '";

    string user2;
    string query3 = "') as subquery\
                        join orders\
                        on subquery.costumer_id = orders.costumer_id) as secondsub\
                        join costumer_orders\
                        on secondsub.order_num = costumer_orders.order_num\
                        order by order_date desc;";

    cout << "please enter the costumer ID  : " << endl;
    cin >> user2;

    query1 = query1 + user2 + query3;
    char* final = stringTochar(query1);

    /** Add MySQL Query */
    mysql_query(connect, final);
    delete final;

    res_set = mysql_store_result(connect);

    if (res_set->row_count == 0)
    {

        system("cls");
        cout << "there is no costumer with that id in store" << endl;
        system("pause");
        system("cls");
        return;
    }

    if (res_set != nullptr && res_set->row_count != 0)
    {
        /*row = mysql_fetch_row(res_set);*/

        cout << "first name | " << "last name | " << "id | " << "order status | " <<"order number | "<< "date contacted | " << "order date" << endl;
        while (((row = mysql_fetch_row(res_set)) != NULL))
        {
            cout << row[0] << " | " << row[1] << " | " << row[2] << " | " << row[3] << " | " << row[4] << " | " << row[5] << " | ";
            if (row[6] != NULL)
                cout << row[6];
            else
                cout << "none";
            cout << " | " << row[7] << endl;
        }
          

    }

    system("pause");
    system("cls");
}

void MySQL::q11()
{
    fflush(stdin);
    const int post_mail = 15;
    const int post_regular = 25;
    const int post_fast = 35;
    const int xprees_pickup = 25;
    const int xpress_delivery = 40;

    string query1 = "select sum(weight) as booksTotalWeight\
                        from(\
                            select weight, book_name\
                            from book_group_id\
                        where book_name = '";

    string query2 = "' or book_name = '";
    string query3 = "' group by book_name) as totalweight;";

    char str[200] = { 0 };
    vector <string> strings;

    std::cout << "what books would you like to send in this delivery?" << endl;
    std::cout << "insert books names deperated by',' : <book_name>,<book_name>,<book_name> " << endl;
    fgets(str, 200 ,stdin);
    splitStr(strings, str);

    int pick = 0;
    bool bad = true;

    while (bad)
    {
        std::cout << "what delivery options would you like to check?" << endl;
        std::cout << "1: israel post - registerd mail." << endl;
        std::cout << "2: israel post - regular courier." << endl;
        std::cout << "3: israel post - fast courier" << endl;
        std::cout << "4: xpress - pickup." << endl;
        std::cout << "5: xpress - courier delivery." << endl;
        std::cout << "please enter the numbr of option you wish to use:" << endl;
        cin >> pick;

        if (pick >= 1 && pick <= 5)
            bad = false;
        system("cls");
    }


    string temp = strings[0];

    for (int i = 1; i < strings.size(); i++)
    {
        temp += (query2 + strings[i]);
    }
        

    query1 += temp + query3;


    char* final = stringTochar(query1);
    mysql_query(connect, final);
    delete final;

    res_set = mysql_store_result(connect);
    string weight;
    string::size_type sz;

    if (res_set != nullptr && res_set->row_count != 0)
    {
        row = mysql_fetch_row(res_set);
        if(row[0] != NULL)
            weight = row[0];
        else
        {
            cout << "the books you have entered does not exist." << endl;
            system("pause"); system("cls");
            return;
        }

    }

    float weight1 = std::stof(weight, &sz);


    switch (pick)
    {
    case 1:
        weight1 *= post_mail;
        break;

    case 2:
        weight1 *= post_regular;
        break;

    case 3:
        weight1 *= post_fast;
        break;

    case 4:
        weight1 *= xprees_pickup;
        break;

    case 5:
        weight1 *= xpress_delivery;
        break;
    };

    cout << "the total weight of the books is: " << weight << "and the price is: " << weight1 << endl;

    system("pause"); system("cls");;

}

void MySQL::q12()
{
    fflush(stdin);
    char buff[100] = { 0 };
    string query1 = "select tracking_code, cost, del_status, company, costumer_id, method\
                        from(\
                            select transaction_id, count(*)\
                            from(\
                                select tracking_code, transaction_id\
                                from deliveries\
                        where transaction_id in(\
                            select transaction_id\
                            from(\
                                select costumer_id, f_name, l_name\
                                from costumers\
                        where costumer_id = '";
    string user;
    string query3 = "') as subquery\
                        join transactions on subquery.costumer_id = transactions.costumer_id)) as secondsub\
                        group by transaction_id\
                        having count(*) > 1) as thirdsub\
                        join deliveries\
                        on thirdsub.transaction_id = deliveries.transaction_id;";


    std::cout << "enter costumer id that you would you like to check:" << endl;
    cin >> user;


    query1 += user + query3;


    char* final = stringTochar(query1);
    mysql_query(connect, final);
    delete final;

    res_set = mysql_store_result(connect);

    if (res_set->row_count == 0)
    {
        system("cls");
        cout << "there is no costumer with that id in store" << endl;
        system("pause");
        system("cls");
        return;
    }

    if (res_set != nullptr && res_set->row_count != 0)
    {
        std::cout << "tracking code | " << "delivery cost | " << "delivery status | " << "company | " << "type "<< endl;
        while (((row = mysql_fetch_row(res_set)) != NULL))
            std::cout << row[0] << " | " << row[1] << " | "<< row[2] << " | " << row[3] << " | "<< row[5]  << endl;

    }

    system("pause"); system("cls");;
}

void MySQL::q13()
{
    string query1 = "select del_status from deliveries where tracking_code ='";
    string user2;
    string query3 = "';";

    cout << "please enter delivery tracking code " << endl;
    cin >> user2;

    query1 = query1 + user2 + query3;
    char* final = stringTochar(query1);

    /** Add MySQL Query */
    mysql_query(connect, final);
    delete final;

    res_set = mysql_store_result(connect);

    if (res_set->row_count == 0)
    {
        system("cls");
        cout << "please enter a valid tracking code. this one does not exist" << endl;
        system("pause");
        system("cls");
        return;
    }

    if (res_set != nullptr && res_set->row_count != 0)
    {
        row = mysql_fetch_row(res_set);
        cout << "delivery status : " << row[0] << endl;
    }

    system("pause"); system("cls");;
}

void MySQL::q14()
{
    string query1 = "select company, sum(cost) from( select tracking_code, company, cost from( select transaction_id from transactions where t_date between '";
    string user2;
    string query3 = "-01'";
    string query4 = "and '";
    string query5 = "-30')";
    string query6 = "as subquery join deliveries on subquery.transaction_id = deliveries.transaction_id) as secondsub where company = 'xpress' ;";

    bool bad = true;
    while (bad)
    {
        cout << "please enter date in format yyyy-mm seperated with comma sign" << endl;
        cin >> user2;
        if (user2[4] != '-')
        {
            system("cls");
            cout << "invalid input, try again" << endl << endl;
            bad = true;
        }
        else
            bad = false;
    }

    query1 = query1 + user2 + query3 + query4 + user2 + query5 + query6;
    char* final = stringTochar(query1);

    /** Add MySQL Query */
    mysql_query(connect, final);
    delete final;

    res_set = mysql_store_result(connect);

 


    if (res_set != nullptr && res_set->row_count != 0)
    {
        row = mysql_fetch_row(res_set);
        if(row[1] != NULL)
            cout << "delivery's cost sum by xpress company : " << row[1] << endl;
        else
        {
            system("cls");
            cout << "there were no deliveries at this month and year by xpress company" << endl;
            system("pause");
            system("cls");
            return;
        }
    }

    system("pause"); system("cls");;
}

void MySQL::q15()
{
    string query1 = "select payment_method, sum(transaction_cost)\
                    from(\
                        select transaction_cost, payment_method, t_date\
                        from transactions\
                    where month(t_date) = '";
    string user2;
    string query3 = "' and year(t_date) = '";
    string query4 = "') as subquery\
                    where payment_method = 'bit';";


    bool bad = true;
    char buff[50] = { 0 };
    while (bad)
    {
        std::cout << "please enter date in format yyyy-mm seperated with comma sign" << endl;
        fgets(buff, 50, stdin);
        if (buff[4] != '-')
        {
            system("cls");
            cout << "invalid input, try again" << endl << endl;
            bad = true;
        }
        else
            bad = false;
    }
    vector <string> strings;
    splitStr(strings, buff);

    query1 += strings[1] + query3 + strings[0] + query4;
    char* final = stringTochar(query1);

    /** Add MySQL Query */
    mysql_query(connect, final);
    delete final;

    res_set = mysql_store_result(connect);



    if (res_set != nullptr && res_set->row_count != 0)
    {
        row = mysql_fetch_row(res_set);
        if( row[1] != nullptr)
           cout << "total money entered to the company's bank account by Bit : " << row[1] << endl;
        else
        {
            system("cls");
            cout << "there were no transfers at this month and year by bit method" << endl;
            system("pause");
            system("cls");
            return;
        }
    }

    system("pause"); system("cls");;
}

void MySQL::q16()
{
    string query1 = "select transaction_id, t_date, transaction_cost from( select transaction_id, t_date, transaction_cost from transactions where t_date < current_date() and t_date > current_date() - interval 1 year) as secondsub where transaction_cost > (select sum(transaction_cost) / 12 from( select t_date, transaction_cost from transactions where t_date < current_date() and t_date > current_date() - interval 1 year) as subquery) ;";


    query1 = query1;
    char* final = stringTochar(query1);

    /** Add MySQL Query */
    mysql_query(connect, final);
    delete final;

    res_set = mysql_store_result(connect);

    if (res_set != nullptr && res_set->row_count != 0)
    {
        /*row = mysql_fetch_row(res_set);*/
  /*      cout << "transaction during last 12 months that made greater profit then the average profit from those last 12 months : " << endl;*/
        cout << "transaction number | " << "transaction date | " <<"transaction cost" << endl;
        while (((row = mysql_fetch_row(res_set)) != NULL))
            cout << row[0] << " | " << row[1] << " | " << row[2] << endl;

    }

    system("pause"); system("cls");;
}

void MySQL::q17()
{
    string query1 = "select company, count(*)\
		from(\
			select transaction_id\
			from transactions\
	where t_date < current_date() and t_date > current_date() - interval 1 year)as subquery\
	join deliveries\
		on subquery.transaction_id = deliveries.transaction_id\
		group by company\
		;";

    query1 = query1;
    char* final = stringTochar(query1);

    /** Add MySQL Query */
    mysql_query(connect, final);
    delete final;

    res_set = mysql_store_result(connect);



    if (res_set != nullptr && res_set->row_count != 0)
    {
        /*row = mysql_fetch_row(res_set);*/
        //cout << "deliveries that executed at the last 12 months  : " << endl;
        cout << "company | " << "number of deliveries | " << endl;
        while (((row = mysql_fetch_row(res_set)) != NULL))
            cout << row[0] << " | " << row[1] << endl;

    }

    system("pause"); system("cls");;
}

void MySQL::q18()
{
    string query1 = "select deliveries.tracking_code, group_id, book_name, cost,\
                        del_status, company, costumer_id, transaction_id, method\
                        from(\
                            select book_group_id.group_id, tracking_code, book_name\
                            from(\
                                select group_id, deliveries_items.tracking_code\
                                from(\
                                    SELECT tracking_code,\
                                    COUNT(tracking_code) AS NumOccurrences\
                                    FROM deliveries_items\
                                    GROUP BY tracking_code\
                                    HAVING(COUNT(tracking_code) > 1)) as subquery\
                                join deliveries_items\
                                on subquery.tracking_code = deliveries_items.tracking_code) as secondsub\
                            join book_group_id\
                    where secondsub.group_id = book_group_id.group_id) as thirdsub\
                    join deliveries\
                        on thirdsub.tracking_code = deliveries.tracking_code;";

    char* final = stringTochar(query1);

    /** Add MySQL Query */
    mysql_query(connect, final);
    delete final;

    res_set = mysql_store_result(connect);

    vector <vector<string >> temp;
    vector <string> in;
    vector <vector<string >> ans;
    int rows = 0;
  
    if (res_set != nullptr && res_set->row_count != 0)
    {
        while (((row = mysql_fetch_row(res_set)) != NULL))
        {
            rows++;
            for (int j = 0; j < 9; j++)
            {
                if(row[j] != NULL)
                    in.push_back(row[j]);
                else
                    in.push_back("null");
            }
            temp.push_back(in);
            in.clear();   
        }
    }

    for (int i = 0; i < rows ; i++)
        for (int j = 0; j < rows; j++)
            if (temp[i][0] == temp[j][0] && temp[i][2] == temp[j][2] && temp[i][1] != temp[j][1] )
                ans.push_back(temp[i]);

    cout << "tracking code | " << "book name | " << "cost | " << "delivery statis | " << "comapny | " << "costumer id | " << "method" << endl;
    for (int i = 0 ; i < ans.size() ; i++)
        cout << ans[i][0] << " | " << ans[i][2] << " | " << ans[i][3] << " | " << ans[i][4] << " | " << ans[i][5] << " | " << ans[i][6] << " | " << ans[i][8] << endl;
     
    system("pause"); system("cls");;
}

void MySQL::q19()
{
    string query1 = "select c.costumer_id, f_name, l_name, landline, join_date, cellphone\
                    from costumers c\
                    join costumer_cellphones cc\
                    on cc.costumer_id = c.costumer_id\
                    join  transactions t\
                    on t.costumer_id = c.costumer_id\
                    where t_date < NOW() - INTERVAL 2 YEAR;";



    query1 = query1;
    char* final = stringTochar(query1);

    /** Add MySQL Query */
    mysql_query(connect, final);
    delete final;

    res_set = mysql_store_result(connect);



    if (res_set != nullptr && res_set->row_count != 0)
    {
        //cout << "information about all costumers who made transactions 2 years ago: " << endl;
        cout << "costumer ID | " << "first name | " << "last name | " << "join date | " << "cellphone" << endl;
        while (((row = mysql_fetch_row(res_set)) != NULL))
            cout << row[0] << " | " << row[1] << " | " << row[2] << " | " << row[4] << " | " << row[5] << endl;

    }

    system("pause"); system("cls");;
}

void MySQL::q20()
{
    string query1 = "select fourthsub.costumer_id, f_name, l_name, cellphone\
                        from(\
                            select costumer_id\
                            from(\
                                select costumer_id, group_id\
                                from(\
                                    select contact_date, costumer_id, book_name\
                                    from(\
                                        select costumer_id, book_name, contact_date\
                                        from orders\
                        where o_status = 'updated' and contact_date is not null) as subquery\
                        where year(NOW()) > year(subquery.contact_date)\
                        or month(NOW()) > month(subquery.contact_date)\
                        or month(NOW()) = month(subquery.contact_date) and day(NOW()) > day(subquery.contact_date)\
                        ) as secondsub\
                        join book_group_id\
                        where secondsub.book_name = book_group_id.book_name) as thirdsub\
                        join transaction_group_id\
                        where thirdsub.group_id = transaction_group_id.group_id) as fourthsub\
                        join(select cost.costumer_id, cellphone, f_name, l_name\
                            from costumers as cost\
                            join costumer_cellphones as cell\
                            on cost.costumer_id = cell.costumer_id) as thejoin\
                            on  fourthsub.costumer_id = thejoin.costumer_id;";


    query1 = query1;
    char* final = stringTochar(query1);

    /** Add MySQL Query */
    mysql_query(connect, final);
    delete final;

    res_set = mysql_store_result(connect);



    if (res_set != nullptr && res_set->row_count != 0)
    {
        /*row = mysql_fetch_row(res_set);*/
      
        cout << "costumer ID | " << "first name | " << "last name | " << "cellphone " << endl;
        while (((row = mysql_fetch_row(res_set)) != NULL))
            cout << row[0] << " | " << row[1] << " | " << row[2] <<" | " << row[3] << endl;

    }

    system("pause"); system("cls");;
}

void MySQL::q21()
{
    string query1 = "select*\
                    from locations_quantity\
                    where location = 'storage';";

    char* final = stringTochar(query1);

    mysql_query(connect, final);
    delete final;

    res_set = mysql_store_result(connect);

    if (res_set != nullptr && res_set->row_count != 0)
    {
        std::cout << "date | " << "quantity | " << endl;
        while (((row = mysql_fetch_row(res_set)) != NULL))
            std::cout << row[1] << " | " << row[2] << endl;

    }

    system("pause"); system("cls");;
}

void MySQL::q22a()
{
    string query1 = "select count(book_sn) as amountOfBooks, sum(bought_price) as totalCost\
		from purchases p\
		join  purchases_books pb\
		on pb.purch_num = p.purch_num\
	where purch_date between '";
    string user2;
    string query2 = "' and '";
    string user3;
    string query3 = "';";

    bool bad = true;
    while (bad)
    {
        cout << "please enter date in format yyyy-mm-dd seperated with comma sign" << endl;
        cin >> user2;
        if (user2[4] != '-' || user2[7] != '-')
        {
            system("cls");
            cout << "invalid input, try again" << endl << endl;
            bad = true;
        }
        else
            bad = false;
    }

    bad = true;
    while (bad)
    {
        cout << "please enter date in format yyyy-mm-dd seperated with comma sign" << endl;
        cin >> user3;
        if (user3[4] != '-' || user3[7] != '-')
        {
            system("cls");
            cout << "invalid input, try again" << endl << endl;
            bad = true;
        }
        else
            bad = false;
    }

    query1 = query1 + user2 + query2 + user3 + query3;
    char* final = stringTochar(query1);

    /** Add MySQL Query */
    mysql_query(connect, final);
    delete final;

    res_set = mysql_store_result(connect);



    if (res_set != nullptr && res_set->row_count != 0)
    {
        row = mysql_fetch_row(res_set);
        if (row[1] != NULL)
        {
            cout << "number of books | " << "total cost" << endl;
            cout << row[0] << " | " << row[1] << endl;
        }
        else
        {
            system("cls");
            cout << "there were no purchases at this month and year by the store" << endl;
            system("pause");
            system("cls");
            return;
        }

    }

    system("pause"); system("cls");;
}

void MySQL::q22b()
{

    string query1 = "select*\
                    from(\
                        select sum(bought_price)\
                        from purchases\
                    where month(purch_date) = '";

    string query7 = "' and year(purch_date) = '";


    string query3 = "') as subquery\
                    join(\
                        select sum(transaction_cost)\
                        from transactions\
                    where month(t_date) = '";

    string query5 = "' and year(t_date) = '";
    string query6 = "') as secondsub;";

    bool bad = true;
    char buff[50] = { 0 };

    while (bad)
    {
        std::cout << "please enter date in format yyyy-mm seperated with comma sign" << endl;
        fgets(buff, 50, stdin);
        if (buff[4] != '-')
        {
            system("cls");
            cout << "invalid input, try again" << endl << endl;
            bad = true;
        }
        else
            bad = false;
    }
    vector <string> strings;
    splitStr(strings, buff);

    query1 += strings[1] + query7 + strings[0] + query3 + strings[1] + query5 +strings[0] + query6;
  /*  cout << query1;*/

    char* final = stringTochar(query1);

    mysql_query(connect, final);
    delete final;

    int in = 0, out = 0;

    res_set = mysql_store_result(connect);

    if (res_set != nullptr && res_set->row_count != 0)
    {
        row = mysql_fetch_row(res_set);
        if (row[0] != NULL && row[1] != NULL)
        {
            in = atoi(row[1]);
            out = atoi(row[0]);
            cout << "year: " << strings[0] << ", month: " << strings[1] << ", the store profit was : " << in - out << endl;
            system("pause"); system("cls");
            return;
        }
        else if (row[0] == NULL && row[1] != NULL)
        {
            in = atoi(row[1]);
            cout << "year: " << strings[0] << ", month: " << strings[1] << ", the store profit was : " << in - out << endl;
            system("pause"); system("cls");
            return;
        }
        else if (row[1] == NULL && row[0] != NULL)
        {
            out = atoi(row[1]);
            cout << "year: " << strings[0] << ", month: " << strings[1] << ", the store profit was : " << in - out << endl;
            system("pause"); system("cls");
            return;
        }
        else
        {
            system("cls");
            cout << "there was income or outcome at this month" << endl;
            system("pause");
            system("cls");
            return;
        }

    }

    

    system("pause"); system("cls");;
}



void MySQL::q23()
{
    string query1 = "select\
                    (select avg(transaction_cost)\
                        from transactions\
                    where month(t_date) = '01'\
                    and year(t_date) = '";

    string query2 = "') as January,\
                        (select avg(transaction_cost)\
                            from transactions\
                        where month(t_date) = '02'\
                        and year(t_date) = '";

    string query3 = "') as Febuary,\
                    (select avg(transaction_cost)\
                        from transactions\
                    where month(t_date) = '03'\
                    and year(t_date) = '";

    string query4 ="') as March,\
                    (select avg(transaction_cost)\
                        from transactions\
                    where month(t_date) = '04'\
                    and year(t_date) = '";

    string query5 = "') as April,\
                    (select avg(transaction_cost)\
                        from transactions\
                    where month(t_date) = '05'\
                    and year(t_date) = '";

    string query6 ="') as May,\
                    (select avg(transaction_cost)\
                        from transactions\
                    where month(t_date) = '06'\
                    and year(t_date) = '";

    string query7 = "') as June,\
                    (select avg(transaction_cost)\
                        from transactions\
                    where month(t_date) = '07'\
                    and year(t_date) = '";

    string query8 ="') as July,\
                    (select avg(transaction_cost)\
                        from transactions\
                    where month(t_date) = '08'\
                    and year(t_date) = '";

    string query9 = "') as August,\
                    (select avg(transaction_cost)\
                        from transactions\
                    where month(t_date) = '09'\
                    and year(t_date) = '";

    string query10 = "') as September,\
                    (select avg(transaction_cost)\
                        from transactions\
                    where month(t_date) = '10'\
                    and year(t_date) = '";

    string query11= "') as October,\
                    (select avg(transaction_cost)\
                        from transactions\
                    where month(t_date) = '11'\
                    and year(t_date) = '";


    string query12 = "') as November,\
                    (select avg(transaction_cost)\
                        from transactions\
                    where month(t_date) = '12'\
                    and year(t_date) = '";

    string query13 = "') as December;";
    string user;

    bool bad = true;


    std::cout << "please enter year in format yyyy seperated with comma sign" << endl;
    cin >> user;
    cin.ignore(INT_MAX, '\n');

    query1 += user + query2 + user + query3 + user + query4 + user + query5 + user + query6 + user + query7 + user + query8 + user + query9 + user +
        query10 + user + query11 + user + query12 + user + query13;

    char* final = stringTochar(query1);

    mysql_query(connect, final);
    delete final;

    res_set = mysql_store_result(connect);

    if (res_set != nullptr && res_set->row_count != 0)
    {
        std::cout << "january | " << "Febuary | " << "March | " << "May | " << "June | " << "July | " << "August | " << "September | " << "October | " << "November | " << "December | " << endl;
        while (((row = mysql_fetch_row(res_set)) != NULL))
        {
            for (int i = 0; i < 12; i++)
            {
                if (row[i] != NULL)
                    cout << row[i] << " | ";
                else
                    cout << " 0 | ";
            }
        }
            
        cout << endl;
    }

    system("pause"); system("cls");;
}

void MySQL::q24()
{
    fflush(stdin);
    string query1 = "select f_name, l_name, salary\
                    from workers a\
                    join salaries w\
                    on w.worker_id = a.worker_id\
                    where w.worker_id = '";

    string query2 = "'and date_m = '";

    string query3 = "'and date_y = '";

    string query4 = "';";

    string id;

    cout << "please enter employee id you wish to check:" << endl;
    cin >> id;
    cin.ignore(INT_MAX, '\n');
    bool bad = true;
    char buff[50] = { 0 };

    while (bad)
    {
        std::cout << "please enter date in format yyyy-mm seperated with comma sign" << endl;
        fgets(buff, 50, stdin);
        if (buff[4] != '-')
        {
            system("cls");
            cout << "invalid input, try again" << endl << endl;
            bad = true;
        }
        else
            bad = false;
    }
    vector <string> strings;
    splitStr(strings, buff);

    query1 += id + query2 + strings[1] + query3 + strings[0] + query4;

    char* final = stringTochar(query1);

    mysql_query(connect, final);
    delete final;

    res_set = mysql_store_result(connect);

    if (res_set->row_count == 0)
    {

        system("cls");
        cout << "no such worker id or no salary for this worker at this month and year" << endl;
        system("pause");
        system("cls");
        return;
    }

    if (res_set != nullptr && res_set->row_count != 0)
    {
        row = mysql_fetch_row(res_set);
        cout << "full name | " << "salary" << endl;
        cout << row[0] << " " << row[1] << " | " << row[2] << endl;
    }

    system("pause"); system("cls");;
}

void MySQL::q25()
{
    string query1 = "select w.f_name, l_name, count(t.worker_id) as amount\
                        from transactions t\
                        join	workers w\
                        on w.worker_id = t.worker_id\
                        where month(t_date) = '";

    string query2 = "' and year(t_date) = '";

    string query3 = "'group by t.worker_id\
                        order by amount desc\
                        limit 1;";


    bool bad = true;
    char buff[50] = { 0 };

    while (bad)
    {
        std::cout << "please enter date in format yyyy-mm seperated with comma sign" << endl;
        fgets(buff, 50, stdin);
        if (buff[4] != '-')
        {
            system("cls");
            cout << "invalid input, try again" << endl << endl;
            bad = true;
        }
        else
            bad = false;
    }
    vector <string> strings;
    splitStr(strings, buff);


    query1 += strings[1] + query2 + strings[0] + query3;
    char* final = stringTochar(query1);

    /** Add MySQL Query */
    mysql_query(connect, final);
    delete final;

    res_set = mysql_store_result(connect);

    if (res_set->row_count == 0)
    {
        system("cls");
        cout << "no worker has sold boks at this year and month" << endl;
        system("pause");
        system("cls");
        return;
    }

    if (res_set != nullptr && res_set->row_count != 0)
    {
        row = mysql_fetch_row(res_set);
        cout << "first name | " << "last name" << endl;
        cout << row[0] << " | " << row[1] << endl;
    }

    system("pause"); system("cls");;
}




