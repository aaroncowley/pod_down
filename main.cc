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

string XMLDownload(string url)
{

}

void MP3Download(string url)
{
    HTTPDownloader downloader;
    string content
}

int main(int argc, char **argv)
{
    cout << "Parsing PODCAST feed" << endl;
    xml_document<> doc;
    xml_node<> * root_node;

    if (argc != 2) {
        cout << "No URL supplied" << endl;
        return 1;
    }

    file<> rssFile(XMLDownload(url));

    doc.parse<0>(rssFile.data());
    root_node = doc.first_node("rss");

    /* Print RSS Version */
    string title = root_node->first_attribute("version")->value();
    cout << "RSS VERSION: " << title << endl;

    /* Dig into the Channel Node */
    root_node = root_node->first_node("channel");
    cout << "PODCAST Title: " << root_node->first_node("title")->value() << endl;

    /* Map for storing podcast title to episode url */
    map<int, string> podcast;

    for (xml_node<> * episode_node = root_node->first_node("item"); episode_node; episode_node = episode_node->next_sibling("item")){
	    	podcast.insert(episode_node->first_node(episode_node->first_node("title")->value(), 
	    	            episode_node->first_node("enclosure")->first_attribute("url")->value());
	}

	

	return 0;
}
    
