#pragma once

namespace Lumix
{


class OutputBlob;
class Path;
class StudioApp;


struct AssetCompiler
{
	struct IPlugin
	{
		virtual ~IPlugin() {}
		virtual bool compile(const Path& src) = 0;
	};

	static AssetCompiler* create(StudioApp& app);
	static void destroy(AssetCompiler& compiler);

	virtual ~AssetCompiler() {}
	virtual void update() = 0;
	virtual void addPlugin(IPlugin& plugin, const char** extensions) = 0;
	virtual void removePlugin(IPlugin& plugin) = 0;
	virtual bool compile(const Path& path) = 0;
	virtual const char* getCompiledDir() const = 0;
	virtual int getMeta(const Path& res, void* buf, int size) const = 0;
	virtual void updateMeta(const Path& res, const void* meta, int size) const = 0;
};


} // namespace Lumix

