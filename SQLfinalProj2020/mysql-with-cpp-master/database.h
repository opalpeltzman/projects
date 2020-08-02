/*
 * ===================================================================
 *
 *       Filename:  database.h
 *
 *    Description:  Declaring MySQL class for using database.
 *
 *        Created:  Friday 22 February 2013 12:48:40  IST
 *       Compiler:  gcc
 *
 *         Author:  Mandeep Kaur, meghasimak@gmail.com
 *        License:  GNU General Public License
 *      Copyright:  Copyright (c) 2013, Great Developers
 *
 * ===================================================================
 */

/**-------------------------------------------------------------------
 *  Include database-detail.h and other files
 *------------------------------------------------------------------*/

#include "header.h"
#include "database-detail.h"


/**
 * ===================================================================
 *        Class:  MySQL
 *  Description:  MySQL class for database accessability
 * ===================================================================
 */

class MySQL
{
    protected:
        /** MySQL connectivity Variables */
        MYSQL *connect;
        MYSQL_RES *res_set;
        MYSQL_ROW row;

        unsigned int i;

    public:
        /** MySQL Constructor */
        MySQL();

        /** Function to show tables in database */
        void ShowTables();

        void mainMenu();
        void worker();
        void owner();
        void q1();
        void q2();
        void q3();
        void q4();
        void q5();
        void q6();
        void q7();
        void q8();
        void q9();
        void q10();
        void q11();
        void q12();
        void q13();
        void q14();
        void q15();
        void q16();
        void q17();
        void q18();
        void q19();
        void q20();
        void q21();
        void q22a();
        void q22b();
        void q23();
        void q24();
        void q25();
        

        char* stringTochar(string str);

        /** MySQL Destructor */
        ~MySQL();
};
