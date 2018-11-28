#include <tinyxml2.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>

using namespace std;
using namespace tinyxml2;

vector<string> split(const string &s, char delim)
{
    stringstream ss(s);
    string item;
    vector<string> elems;
    while (getline(ss, item, delim))
    {
        elems.push_back(item);
    }
    return elems;
}

void findTransforms(XMLNode *parent, map<XMLElement*, vector<glm::mat4>> &tnodes)
{
    XMLNode *node = parent->FirstChild();

    while (node != nullptr)
    {
        findTransforms(node, tnodes);

        XMLElement *typeName = node->FirstChildElement("typename");
        string scatter = "scatter";
        if (typeName != nullptr && scatter.compare(typeName->GetText()) == 0)
        {
            XMLElement* telem = node->FirstChildElement("parameters")->FirstChildElement("transforms");
            string tstring = telem->GetText();
            vector<string> floats = split(tstring, ' ');
            vector<glm::mat4> matrices;
            size_t n = floats.size() / 16;
            for (size_t i = 0; i != n; ++i)
            {
                float m[16];
                for (int j = 0; j != 16; ++j)
                {
                    m[j] = atof(floats[i * 16 + j].c_str());
                }
                matrices.push_back(glm::make_mat4(m));
            }

            tnodes.insert(make_pair(telem, matrices));
        }

        node = node->NextSibling();
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cerr << "Please set ocs file." << endl;
        return -1;
    }

    char *ocsFile = argv[1];

    XMLDocument doc;
    doc.LoadFile(ocsFile);

    map<XMLElement*, vector<glm::mat4>> tnodes;
    findTransforms(&doc, tnodes);

    if (tnodes.empty())
    {
        cerr << "Can not find transforms." << endl;
        return -1;
    }

    //modify tnodes then save doc;
    //XMLElement::SetText

    doc.SaveFile( "./test.ocs" );

    return 0;
}