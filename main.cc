#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <rapidxml/rapidxml.hpp>
#include <rapidxml/rapidxml_print.hpp>
#include <rapidxml/rapidxml_utils.hpp>

using std::vector;
using std::cout;
using std::endl;
using std::string;
using namespace rapidxml;

int main(void)
{
    cout << "Parsing PODCAST feed" << endl;
    xml_document<> doc;
    xml_node<> * root_node;

    file<> rssFile("feed.xml");

    doc.parse<0>(rssFile.data());
    root_node = doc.first_node("rss");

    /* Print RSS Version */
    string title = root_node->first_attribute("version")->value();
    cout << "RSS VERSION: " << title << endl;

    /* Dig into the Channel Node */
    root_node = root_node->first_node("channel");
    cout << "PODCAST Title: " << root_node->first_node("title")->value() << endl;

    for (xml_node<> * episode_node = root_node->first_node("item"); episode_node; episode_node = episode_node->next_sibling("item")){
	    printf("Episode %s in %s. ", 
	    	episode_node->first_node("title")->value(),
	    	episode_node->first_node("enclosure")->first_attribute("url")->value());
            // Interate over the beers 
	    cout << endl;
	}
}
    
