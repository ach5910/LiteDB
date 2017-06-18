# ft_db

INSTALLATION
- Clone repostitory
- Run make in root directory
- Must have a terminal open for both the server and the client
- From root directory run ./server followed by a valid port number
- From root direct connect a client to the running server by executing ./client localhost followed the same port number used to initailize the server executable

INSTRUCTIONS
- All commmands are must be space separated include between '=' and conditionals
- If the command supports the WHERE clause then the following conditions apply

  WHERE:
  - A valid WHERE clause is appended the to the end of the command in this format
    WHERE [valid field name] = [data value]
    WHERE [valid field name] < [data value]
    WHERE [valid field name] > [data value]
    WHERE [valid field name] < [first limit] AND > [second limit]
    WHERE [valid field name] > [first limit] OR < [second limit]
  - Limits must be of the same data type as the field name
  
- If the WHERE clause is not added then the command will effect then entire table
- The followed commands are supported and are all case insensitive
  SELECT
  UPDATE
  INSERT
  DELETE
  CREATE
  DROP
  
  SELECT:
  - SELECT [valid field name][* to return all fields][id] FROM [table name]
  - Supports WHERE clause
  
  UPDATE:
  - UPDATE [table name] SET [valid field name] = [new value]
  - Supports WHERE clause
  
  INSERT:
  - INSERT [table name] VALUES [field]
  - All fields must be present and in accordance with the limits set in the TABLES header. This means data type, string length for strings and value size for ints, both upper and lower bounds
  
  DELETE:
  - DELETE FROM [table name]
  - Supoprt WHERE clause
  
  CREATE:
  - CREATE TABLE [new table name] [field name]=[char or int]([lower bound]~[upper bound]), ...
  - Setting the fields are all one string and are terminated by an ',' if more fields follow
    ex. CREAT TABLE teams name=char(5~25), players=int(20~30)
      This will create a table named TEAMS with a char field called name where entries must have a string length between
      5 and 25, and another field name called players where the entries must be between 20 and 30
  - Setting the fields is what the validation check will compare against when an INSERT or UPDATE command is entered
  
  DROP:
  - DROP TABLE [table new]
  
FEATURES
- Rigorous validation checks and error handling
- Server/Client connection
- Range queries supporting logical operators
- Mutliple sting names can be entered by encapsulating them within single quotes ie. 'Aaron Hunt'
- Queries can return all fields or idivdual fields
- Field id is automatically added to all fields and properly incremented
- Data types can either be strings or ints
- WHERE clause properly compares int fields numerically and string fields lexographically
- TABLE file contains table header information including table name, number of fields and valid field format
- Each table will contain it's own file with titled by the table name and will contain number of fields, last id entered, and number of rows
