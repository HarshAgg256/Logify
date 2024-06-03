#include<iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

/// @brief This integer variable stores the current line number of the proof we are on.
int m;

/// @brief Class Stack
///
///This class implements stack data structure using a 1-d array.
///### Variable 
/// int* arr : It points to the array using which we'll be implementing stack
///
/// int top : It points to the top value of the stack.

class stack
{
    int* arr;
    int top;
    int z=100;
    public:

    /// @brief Constructor
    ///
    /// It constructs an object of class stack with initialization of an array and giving default value -1 to the top pointer.
    stack()
    {
        arr = new int[z];
        top=-1;
    }

    /// @brief Push Function
    ///
    /// This function is used to push a value at the top of the stack when called.
    /// It returns as it is when the stack is full.
    /// @param a The value required to be pushed.
    void push(char a)
    {
        if(top==z-1)
        {
            return;
        }
        top++;
        arr[top]=a;
    }

    /// @brief Pop Function
    ///
    /// This function is used to remove the topmost value of the stack when called.
    /// It returns as it is when the stack is empty.
    void pop()
    {
        if(top==-1)
        {
            return;
        }
        top--;
    }

    /// @brief atTheTop Function
    ///
    /// This function is used to get the value present at the top of stack.
    /// It returns -1 when the stack is empty.
    /// @return Stack's top value
    int atTheTop()
    {
        if(top==-1)
        {
            return -1;
        }
        return arr[top];
    }

     /// @brief length Function
    ///
    /// This function is used to check the length of our stack.
    /// @return the value of top of the stack.
    int length()
    {
        return top;
    }


    /// @brief This method is used to empty the stack 
    void empty()
    {
      top =-1;
    }
};


/// @brief This function facilitates in detection of any parenthesization errors in propositional formulas of each 
///        proof line in formula_validity() function
///
/// @param str This string contains the propositional formula i.e., substring before first '/' character in each proof line.
/// @param s This is the character whose number of occurences are to be calculated in string str.
/// @return The number of occurences of character s in string str.
///
/// ### Variables
///
/// - **count (int)** : Stores the count of character s in the input string str.
/// 
/// @see formula_validity

int no_of_occurences(string str,char s)
{
    int count=0;
    for(int i=0;i<str.length();i++)
    {
        if(str[i]==s)
        {
            count++;
        }
    }
    return count;
}

/// @brief This function checks if the current character is a propositional atom. 
///
/// @param c The character which can be an operator, a propositional atom or bracket.
/// @return This function returns true only if the current character is an English alphabet (small case or capital case). 
/// @note The user is advised to use only small case English alphabet letters to denote propositional atoms.
/// @see formula_validity

bool is_alpha(char c)
{
    return (c>=65 && c<=90) || (c>=97 && c<=122);
}

/// @brief This function takes note of whether each proof line contains valid propositional formulas with perfect parenthesization.
/// @param formula This string argument stores the propositional formula (<statement>) present in the 
///                   current line(jth line) of the proof i.e., substring before first '/'.
/// @param j This integer argument holds the line number we are currently on.
/// @return This function returns true if the propositional formula is found valid and false if found invalid.
///
/// ### Working
///
/// This function first of all calls no_of_occurences() function for checking if number of opening and closing brackets are equal. If not, 
/// false is returned and pushed back into trueness array. Otherwise, it carries out a loop to hover over each character of the formula string 
/// and check its neighbouring characters. Depending upon a given current character, its neighbouring characters can only be one of the few valid
/// ones. If an invalid neighbouring character is encountered, false is returned and pushed back into trueness array. Else, if all the neighbouring
/// characters of the current character are valid, next iteration is triggered via continue statement to hover over the next character.
/// Encountering zero invalidities leads to return of true value and its pushing back into trueness array. 
/// 
/// ### If Current Character is a propositional atom:
///  - **Invalid neighbouring characters on LHS** : ')' , an atom
///  - **Invalid neighbouring characters on RHS** : '~' , '(' , an atom
///
/// ~~~~.cpp
/// else if(is_alpha(formula[i]))
///{
///    if(formula[i-1] == ')' || is_alpha(formula[i-1]) || formula[i+1] == '~' || formula[i+1] == '(' || is_alpha(formula[i+1]))
///    {
///        cout<<"Line number "<<j<<" is Not a Propositional Formula\n";
///        return false;
///    }
///    else
///    {
///        continue;
///    }
///}
/// ~~~~
///
/// ### If Current Character is an negation operator:
///  - **Valid neighbouring characters on LHS** : '+' , '*' , '>' , '('
///  - **Valid neighbouring characters on RHS** : '(' , an atom
///
/// ~~~~.cpp
/// else if(formula[i]=='~')
///{
///    if((formula[i-1] == '+' || formula[i-1] == '*' || formula[i-1] == '>' || formula[i-1] == '(') && (is_alpha(formula[i+1]) ||formula[i+1] == '('))
///    {
///        continue;
///    }
///    else
///    {
///        cout<<"Line number "<<j<<" is Not a Propositional Formula\n";
///        return false;
///    }
///}
/// ~~~~
/// ...... AND SO ON for other current operators
///
///
bool formula_validity(string formula,int j)
{
    formula = '(' + formula + ')';

    if(no_of_occurences(formula,'(')==no_of_occurences(formula,')'))
    {
        for(int i=0;i<formula.length();i++)
        {
            if(formula[i]==')' || formula[i]=='(')
            {
                continue;
            }
            else if(formula[i]=='*')
            {
                if((is_alpha(formula[i-1]) || formula[i-1] == ')') && (is_alpha(formula[i+1]) || formula[i+1] == '(' || formula[i+1] == '~'))
                {
                    continue;
                }
                else
                {
                    cout<<"Line number "<<j<<" is Not a Propositional Formula\n";
                    return false;
                }
            }
            else if(formula[i]=='+')
            {
                if((is_alpha(formula[i-1]) || formula[i-1] == ')') && (is_alpha(formula[i+1]) || formula[i+1] == '(' || formula[i+1] == '~'))
                {
                    continue;
                }
                else
                {
                    cout<<"Line number "<<j<<" is Not a Propositional Formula\n";
                    return false;
                }
            }
            else if(formula[i]=='>')
            {
                if((is_alpha(formula[i-1]) || formula[i-1] == ')') && (is_alpha(formula[i+1]) || formula[i+1] == '(' || formula[i+1] == '~'))
                {
                    continue;
                }
                else
                {
                    cout<<"Line number "<<j<<" is Not a Propositional Formula\n";
                    return false;
                }
            }
            else if(formula[i]=='~')
            {
                if((formula[i-1] == '+' || formula[i-1] == '*' || formula[i-1] == '>' || formula[i-1] == '(') && (is_alpha(formula[i+1]) || formula[i+1] == '('))
                {
                    continue;
                }
                else
                {
                    cout<<"Line number "<<j<<" is Not a Propositional Formula\n";
                    return false;
                }
            }
            else if(is_alpha(formula[i]))
            {
                if(formula[i-1] == ')' || is_alpha(formula[i-1]) || formula[i+1] == '~' || formula[i+1] == '(' || is_alpha(formula[i+1]))
                {
                    cout<<"Line number "<<j<<" is Not a Propositional Formula\n";
                    return false;
                }
                else
                {
                    continue;
                }
            }
        }
        return true;
    }
    else
    {
        cout<<"Parenthesization Error in Line number "<<j<<"\n";
        return false;
    }
}


///@brief The checker function inspects if the proof rules are implemented correctly in that particular line.
///
/// \param proof[] - The string array containing the entire proof, with each line contained in one row of the vector.
/// \param seglist[] - This vector contains the divided string containing the propositional formula, proof and the lines the rule is implemented on.
/// ### Variables
/// - **str** (String): This variable stores the propositional logic after implementation of the rules.
///
/// - **expected_output** (String): This variable stores the propositional logic after implementation of the OR introduction rule.
///
/// - **s** (String): This is the substring of the proof from beginning till the end of proof before /.
///
/// - **index** (int): This variable stores the position where expected_output is found in the seglist[0].
///
/// ### OR Introduction
///
///This snippet of the code checks OR introduction rule. It applies the or introduction rule to the element on seglist[2] and checks equivalency with the proof. And based on the outcome returns the value as true or false.
///The following snippet is for OR introduction 2, the same is done for OR introduction 1.
///
///~~~~.cpp
///expected_output = '+' + s + ')';
///bool index = seglist[0].compare(seglist[0].length() - expected_output.length(), expected_output.length(), expected_output);
///if(index == 0)
///{
///     return true;
///}
///return false;
///~~~~
///
/// ### And Introduction
///This snippet of the switch case traverses to those lines on which and introduction rule is implemented, and after implementing the rule stores it in string str.
/// @note This snippet also checks whether the rule implemented on the propositional formulae have occurred before the current proof line.
///
///
///~~~~.cpp
///if(stoi((seglist[2]))>=m||stoi((seglist[3]))>=m)
///     return false;
///str='('+proof[stoi(seglist[2])].substr(0,proof[stoi(seglist[2])].find('/'))+'*'+proof[stoi(seglist[3])].substr(0,proof[stoi(seglist[3])].find('/'))+')';
///break;
///~~~~
///
//////###AND ELIMINATION
///
///We use a stack method to overcome the challenge of multiple and operator within a proof
///
///We run a loop over the whole proof and push " ( " and " ) " inside the stack whenever encountered  
///
///Whenever there is a pair of "(" and ")" we delete both from the stack
///
///The and operator (*) encountered is only implemented if and only if there is only one " ( " present in the stack at the time of encountering the and symbol
///
/// Checking for e1:
///~~~~.cpp
///for(i=0;i<proof[stoi(seglist[2])].length();i++)
///{
///  if(proof[stoi(seglist[2])][i]=='(')
///  {
///    st.push('(');
///  }
///  if(proof[stoi(seglist[2])][i]==')')
///  {
///    st.pop();
///  }
///  if(proof[stoi(seglist[2])][i]=='*')
///{
///  if(st.length()==0)
///  {
///  str=proof[stoi(seglist[2])].substr(1,i-1);
///  break;
///}}}
///~~~~
///
///
/// str string now contains the proof lines until encountering * excluding opening "("
///
/// ### IMPLICATIONS
/// 
///
///
/// Brief - when ' > ' is detected in a switch case then we enter in this case and check for implication elimination
///
///
///###Variables - 
///
/// - stack **st** - object of class stack 
///
/// - string **strp** - string used to store part of proof line before implication 
///
/// - string **stm** - string used to store part of proof line in given number until '/' is encountered
///
/// - string **pt** - string used to store part of proof line in given number until '/' is encountered
///
/// - string **mp** - string used to store part of proof line post implication until '/' is encountered 
///
/// - string **kt** - string used to store negation of mp
///
/// - string **lt** - string used to store negation of lt
///
///### Modus Ponens
/// we trim the required proof lines until we find '/'
///~~~~.cpp
///string stm = proof[stoi(seglist[2])].substr(0,proof[stoi(seglist[2])].find('/'));
///
///string pt = proof[stoi(seglist[3])].substr(0,proof[stoi(seglist[3])].find('/'));
///
///~~~~
///
///
///
/// @note As discussed in the case of ' * ' we use stack method here too.
///
///
///
/// Stack Implementation for Modus Ponens:
///~~~~.cpp
///for(i=0;i<proof[stoi(seglist[2])].length();i++)
///{
///if(proof[stoi(seglist[2])][i]=='(')
///  {
///    st.push('(');
///  }
///  if(proof[stoi(seglist[2])][i]==')')
///  {
///    st.pop();
///  }
///  if(proof[stoi(seglist[2])][i]=='>')
///{
///  if(st.length()==0)
///  {
///  strp=proof[stoi(seglist[2])].substr(1,i-1);
///  break;
///}}}
///~~~~
///
///
///We compare the logic code before implication with the next given proof line and also check the logic code post implication with current proof line 
///
///
///###Modus Tollens
///
///
/// Brief - when ' MT ' is detected in a switch case then we enter in this case and check for possibility of modulus tollens
///
//////We trim the required proof lines until we find '/'
///
///
///@note As discussed in the case of ' * ' we use stack method here too.
///
///
///We create seperate strings in order to compare the negations of them with the given proof lines
///
///
///Negation of Propositional Formula:
///~~~~.cpp
///string kt='~'+mp;
///string lt='~'+strp;
///~~~~
///
///
///We compare the logic code before implication with the negation of current given proof line and also check the logic code post implication with negation of given proof line 
///
///
/// Comparing Proofs:
///~~~~.cpp
///if(pt == strp)
///{
///if(seglist[0]==mp)
///return true;
///}
///else
///return false;
///~~~~
///
/// \return bool value TRUE or FALSE

bool checker(string proof[], vector<string> seglist)
{ string str;


    switch(seglist[1][0])
    {
      case 'P':
      return true;
        case '+':
        {   if(stoi(seglist[2])>=m)
          return false;
          if(seglist[1][1]!='i')
          return false;
            string expected_output;
            string s = proof[stoi(seglist[2])].substr(0,proof[stoi(seglist[2])].find('/'));
            switch(seglist[1][2])
            {
                case '1':
                {
                    expected_output = '(' + s + '+';
                    int index = seglist[0].find(expected_output);
                    if(index == 0)
                    {
                        return true;
                    }
                    return false;
                }

                case '2':
                {   expected_output = '+' + s + ')';
                    bool index = seglist[0].compare(seglist[0].length() - expected_output.length(), expected_output.length(), expected_output);
                    if(index == 0)
                    {
                        return true;
                    }
                    return false;
                }

                default:
                {
                    return false;
                }

            }
        }

        case '*':
        {
          switch(seglist[1][1]){
            case 'i':
            {
              if(stoi((seglist[2]))>=m||stoi((seglist[3]))>=m)
              return false;
            str='('+proof[stoi(seglist[2])].substr(0,proof[stoi(seglist[2])].find('/'))+'*'+proof[stoi(seglist[3])].substr(0,proof[stoi(seglist[3])].find('/'))+')';
            break;
            }
            case 'e':
            { if(stoi(seglist[2])>=m)
              return false;
              stack st; int i;
              switch(seglist[1][2]){
                case '1':
                {for(i=0;i<proof[stoi(seglist[2])].length();i++)

                  {
                    if(proof[stoi(seglist[2])][i]=='(')
                    {
                      st.push('(');
                    }
                    if(proof[stoi(seglist[2])][i]==')')
                    {
                      st.pop();
                    }
                    if(proof[stoi(seglist[2])][i]=='*')
                  {
                    if(st.length()==0)
                    {
                    str=proof[stoi(seglist[2])].substr(1,i-1);
                    break;
                  }
                  }
                }
                  st.empty();
                  break;}
                case '2':
                {for(i=0;i<proof[stoi(seglist[2])].length();i++)

                  {
                    if(proof[stoi(seglist[2])][i]=='(')
                    {
                      st.push('(');
                    }
                    if(proof[stoi(seglist[2])][i]==')')
                    {
                      st.pop();
                    }
                    if(proof[stoi(seglist[2])][i]=='*')
                  {
                    if(st.length()==0)
                    {
                  str=proof[stoi(seglist[2])].substr(i+1, proof[stoi(seglist[2])].find('/')-2-i);
                  break;
                }
              }
            }
            st.empty();
            break;
          }
                default:
                return false;
              }
              break;}
            default:
             return false;

          }
        break;
      }
      case '>':
      { if(stoi((seglist[2]))>=m||stoi(seglist[3])>=m)
      return false;
        int i;
        stack st;
        string strp;
        switch(seglist[1][1]){
            case 'e':
            {
                string stm = proof[stoi(seglist[2])].substr(0,proof[stoi(seglist[2])].find('/'));
                string pt = proof[stoi(seglist[3])].substr(0,proof[stoi(seglist[3])].find('/'));
                for(i=0;i<proof[stoi(seglist[2])].length();i++)

                  {
                    if(proof[stoi(seglist[2])][i]=='(')
                    {
                      st.push('(');
                    }
                    if(proof[stoi(seglist[2])][i]==')')
                    {
                      st.pop();
                    }
                    if(proof[stoi(seglist[2])][i]=='>')
                  {
                    if(st.length()==0)
                    {
                    strp=proof[stoi(seglist[2])].substr(1,i-1);
                    break;
                  }
                  }
                }
                size_t found = stm.find('>');
                if (found == string::npos)
                {return false;


                }
                st.empty();
                string mp= stm.substr(i+1,stm.length()-i-2);
                if(pt == strp){
                    if(seglist[0]==mp)
                    return true;
                }
                else
                return false;
            }
        default :
        return false;
        }
      }
      case 'M':
      { if(seglist[1][1]!='T')
      return false;
        if(stoi((seglist[2]))>=m||stoi(seglist[3])>=m)
      return false;
        int i;
        stack st;
        string strp;

                string stm = proof[stoi(seglist[2])].substr(0,proof[stoi(seglist[2])].find('/'));
                string pt = proof[stoi(seglist[3])].substr(0,proof[stoi(seglist[3])].find('/'));
                for(i=0;i<proof[stoi(seglist[2])].length();i++)

                  {
                    if(proof[stoi(seglist[2])][i]=='(')
                    {
                      st.push('(');
                    }
                    if(proof[stoi(seglist[2])][i]==')')
                    {
                      st.pop();
                    }
                    if(proof[stoi(seglist[2])][i]=='>')
                  {
                    if(st.length()==0)
                    {
                    strp=proof[stoi(seglist[2])].substr(1,i-1);
                    break;
                  }
                  }
                }
                size_t found = stm.find('>');
                if (found == string::npos)
                {return false;
                }
                st.empty();
                string mp= stm.substr(i+1,stm.length()-i-2);
                string kt='~'+mp;
                string lt='~'+strp;
                if(kt == pt){
                    if(seglist[0]==lt)
                    return true;
                }
                else
                return false;

      }
        default:
        {
            return false;
        }
    }
if(str==(seglist[0]))
return true;
else
return false;
}

/// This is the main function of our program, that calls other functions, takes input values from the user and displays the outputs.
///
/// ### Variables/Objects
///
/// - **no_of_lines (int)** : Stores the number of lines the user's proof can be accomodated in.
///
/// - **proof [] (String Array)** : Array of strings which stores each line of the entered proof 
///                          i.e., Accessing an element of this array is equivalent to accessing the corresponding line of proof.
///
/// - **trueness [] (Bool Array)** : This Array of size no_of_lines stores true or false determined/decided by whether the corresponding proof 
///                           lines contain valid propositional formulas or not.
///
/// - **formula (string)** : For each iteration, this string stores the propositional formula (<statement>) present in the 
///                   corresponding line of the proof i.e., substring before first '/'.
/// 
/// - **proof_line (string)** : For each iteration, this string stores corresponding line of the proof.
///
/// - **segment (string)** : For a single line of proof, this string iteratively stores line's segments broken via '/' character.
///
/// - **seglist (String Vector)** : For a single line of proof, this vector of strings stores the segmented parts of each 
///                           proof line broken via '/' character.
///
/// ### Working
/// 
/// After taking no_of_lines and the proof as input from the user, the main function calls for each proof line the formula_validity() function to 
/// check if the propositional formula is valid or not. If any one of the lines returns false, the program terminates. Otherwise, seglist vector
/// is created and the control goes on to checker() function to check if the proof rules are implemented correctly in that particular line. 
/// Here is an example of how are things going on in main function: 
///
///
///
///
///
/// ![](table.png)
/// 
/// @see formula_validity()
/// @see checker
///
/// @note Our main function also prints the line number of error occurence in the proof.
///
/// @attention The user has to use:
///                               - '~' for negation operator
///                               - '+' for OR operator
///                               - '*' for AND operator
///                               - '>' for IMPLICATION operator
///            Exercise perfect parenthesization. Don't use '(' before '~' operator in simple formulas like (p+~(q*r)), ~(q>s)
///            It is to be added before '~' only for compound formulas like (~(q+r)*(p>s))
///             
/// 
/// @warning The program may misbehave if the user enters some alphanumeric strings instead of integer for no_of_lines.
///
int main()
{
    int no_of_lines;
    cout<<"Enter the number of lines your proof can be accommodated in:\n";
    cin>>no_of_lines;
    cout<<"Enter the proof:\n";

    string proof[no_of_lines+1];

    for(int i=0;i<no_of_lines+1;i++)
    {
        getline(cin,proof[i]);
    }
 
    bool trueness[no_of_lines]; 

    for(int j=1;j<no_of_lines+1;j++)
    {
        string formula = proof[j].substr(0,proof[j].find('/'));
        trueness[j-1] = formula_validity(formula,j);
    }

    for(int i = 0; i<no_of_lines;i++)
    {
        if(trueness[i]==false)
        {
            cout<<"Cannot Proceed Further";
            return 0;
        }
    }

    for(m=1;m<no_of_lines+1;m++)
    {
        string proof_line = proof[m];
        stringstream ss(proof_line);
        string segment;
        vector<string> seglist;

        while(getline(ss, segment, '/'))
        {
            seglist.push_back(segment);
        }

        if(checker(proof,seglist))
        {
            continue;
        }
        else
        {
            cout<<"\nThe Proof is invalid. Line "<<m<<" possesses some incorrectness";
            return 0;
        }
    }
    cout<<"The proof is valid.";
    return 0;
}