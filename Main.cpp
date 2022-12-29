#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>

typedef struct
{
    short value;
    std::string file;
}Var;

std::string current_file;

std::vector<std::string> split(const std::string& str, char delimiter)
{
    std::vector<std::string> arr;
    std::stringstream ss(str);
    std::string s;
    while (getline(ss, s, delimiter)) {
        arr.push_back(s);
    }
    return arr;
}
std::string readFile(std::string file)
{
    std::ifstream f(file);
    std::string l;
    std::string str;
    if (f.is_open()) {
        while (f) {
            std::getline(f, l);
            str += l + "\n";
        }
    }
    else {
        std::cout << "Couldn't open file\n" << file << std::endl;
    }

    return str;
}
//internal variables
std::unordered_map<std::string, std::string> m_Files;
std::unordered_map<std::string, Var> m_Variables;
std::unordered_map<std::string, Var> m_GlobalVariables;

short ec = 0;
bool isVar(const std::string& str)
{
    return m_Variables.find(str) != m_Variables.end() || m_GlobalVariables.find(str) != m_GlobalVariables.end();
}

short& getVar(const std::string& str)
{
    if (m_Variables.find(str) != m_Variables.end() && m_Variables.at(str).file == current_file)
		return m_Variables.at(str).value;
    else if(m_GlobalVariables.find(str) != m_GlobalVariables.end())
        return m_GlobalVariables.at(str).value;
}

void execCode(std::string file)
{
    std::string source = readFile(file);
    std::vector<std::string> code = split(source, '\n');

    size_t i = 0;
    while (i < code.size() - 1)
    {
		if(empty(code[i]))
			i++;
        std::vector<std::string> line = split(code[i], ' ');
        if (line[0] == "exit")
        {
            ec = std::stoi(line[1]);
            break;
        }
        else if(line[0] == "execute")
        {
            //execute --namespace--
            current_file = file;
            execCode(m_Files[line[1]]);
            i++;
        }
		else if (line[0] == "print")
        {
            for (size_t i = 1; i < line.size(); i++) {
                std::string str = line[i];
                if(!isVar(str)){
                    for (size_t i = 0; i < str.length(); i++)
                    {
                        if (str[i] == '_')
                        str[i] = ' ';
                    }
                    
                    std::cout << str << std::endl;
                }
				else
					std::cout << getVar(str) << std::endl;
            }
            i++;
        }
		else if (line[0] == "set")
        {
            if(!isVar(line[2]))
                getVar(line[1]) = std::stoi(line[2]);
            else
                getVar(line[1]) = getVar(line[2]);
            i++;
        }
        else if (line[0] == "var")
        {
            m_Variables[line[1]].file = current_file;
            m_Variables[line[1]].value = std::stoi(line[2]);
            i++;
        }
        else if (line[0] == "global")
        {
            m_GlobalVariables[line[1]].file = current_file;
            m_GlobalVariables[line[1]].value = std::stoi(line[2]);
            i++;
        }
        else if (line[0] == "sum")
        {
            if (!isVar(line[2]))
                getVar(line[1]) += std::stoi(line[2]);
            else
                getVar(line[1]) += getVar(line[2]);
            i++;
        }
        else if (line[0] == "sub")
        {
            if (!isVar(line[2]))
                getVar(line[1]) -= std::stoi(line[2]);
            else
                getVar(line[1]) -= getVar(line[2]);
            i++;
        }
        else if (line[0] == "mul")
        {
            if (!isVar(line[2]))
                getVar(line[1]) *= std::stoi(line[2]);
            else
                getVar(line[1]) *= getVar(line[2]);
            i++;
        }
        else if (line[0] == "div")
        {
            if (!isVar(line[2]))
                getVar(line[1]) /= std::stoi(line[2]);
            else
                getVar(line[1]) /= getVar(line[2]);
            i++;
        }

        else if (line[0] == "jump")
            i = std::stoi(line[1])-1;

        else if (line[0] == "lump")
        {
            if (!isVar(line[3]))
                if (getVar(line[2]) < std::stoi(line[3]))
                    i = std::stoi(line[1])-1;
                else
                    i++;
            else
                if (getVar(line[2]) < getVar(line[3]))
                    i = std::stoi(line[1])-1;
                else
                    i++;
        }
        else if (line[0] == "gump")
        {
            if (!isVar(line[3]))
                if (getVar(line[2]) > std::stoi(line[3]))
                    i = std::stoi(line[1])-1;
                else
                    i++;
            else
                if (getVar(line[2]) > getVar(line[3]))
                    i = std::stoi(line[1])-1;
                else
                    i++;
        }
        else if (line[0] == "eump")
        {
            if (!isVar(line[3]))
                if (getVar(line[2]) == std::stoi(line[3]))
                    i = std::stoi(line[1])-1;
                else
                    i++;
            else 
                if (getVar(line[2]) == getVar(line[3]))
                    i = std::stoi(line[1])-1;
                else
                    i++;
        }
		else if(line[0] == "input")
		{
			std::cin >> getVar(line[1]);
			i++;
		}
		else if(line[0] == "read")
		{
			std::string str = readFile(line[1]);
			std::vector<std::string> file = split(str, '\n');
			getVar(line[3]) = std::stoi(file[std::stoi(line[2])-1]);
            i++;
		}
		else
			i++;
    }
    return;
}

int main()
{
    std::string file = "Main.block";
    std::string p = "Project.block";

    std::vector<std::string> projectFile = split(readFile(p), '\n');
    size_t i = 0;
    while (i < projectFile.size() - 1)
    {
        if(projectFile[i].empty())
            i++;
        std::vector<std::string> line = split(projectFile[i], ' ');
        if(line[0] == "import")
        {
            //import --file-- --name--
            m_Files[line[2]] = line[1];
            i++;
        }
    }
    execCode(file);
    
	std::cout << "exit code " << ec;

    std::cin.get();
    return ec;
}