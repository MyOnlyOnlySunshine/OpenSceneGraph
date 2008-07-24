/* -*-c++-*- OpenSceneGraph - Copyright (C) 1998-2008 Robert Osfield 
 *
 * This application is open source and may be redistributed and/or modified   
 * freely and without restriction, both in commericial and non commericial applications,
 * as long as this copyright notice is maintained.
 * 
 * This application is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#ifndef PLUGINQUERY_H
#define PLUGINQUERY_H

#include <list>

namespace osgDB
{

typedef std::list<std::string> FileNameList;


FileNameList listAllAvailablePlugins();

class ReaderWriterInfo : public osg::Referenced
{
    public:
    
        std::string                         plugin;
        std::string                         description;
        ReaderWriter::FormatDescriptionMap  protocols;
        ReaderWriter::FormatDescriptionMap  extensions;
        ReaderWriter::FormatDescriptionMap  options;
};

typedef std::list< osg::ref_ptr<ReaderWriterInfo> > ReaderWriterInfoList;

bool queryPlugin(const std::string& fileName, ReaderWriterInfoList& infoList);

bool outputPluginDetails(std::ostream& out, const std::string& fileName);

}

#endif
