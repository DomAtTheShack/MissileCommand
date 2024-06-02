#ifndef GAMEASSETSLOADER_LIBRARY_H
#define GAMEASSETSLOADER_LIBRARY_H

#include <string>
#include <zip.h>
#include <vector>

#define DARW_INFO_FILE ".info.rc"
#define INFO_NAME "file_name"
#define INFO_DATE "date"

/**
 * This holds the current zip file information as the NAME of the file, DATE it was created, and the SHA256 of the file
 */
struct info
{
    std::string NAME;
    std::string DATE;
};

/**
 * This is the init function to load in the assets file into RAM\n
 * Also allows loadAssetsInfo() to be run
 * @param assetsFileName the assets.darw file to be loaded in
 * @return returns true if everything worked as expected and loaded in if something failed then returns false
 */
bool initAssets(char* assetsFileName);

/**
 * This loads the asset info a struct and loads with the name of the file, date it was created, and the sha256 of the file\n
 * Also checks the sha256 to the file and won't load if incorrect
 * @return This returns the struct that has the NAME, DATE, and SHA variables if everything was found if not then returns all null
 */
info loadAssetsInfo();

/**
 * This will first check if the z variable is loaded and the loadAssetsInfo() has run successfully  \n
 * Then it will print out the directory and file layout of the archive
 * @return This will return true if able to read the file false if something goes wrong
 */
bool listAssets();

/**
 * This will first check if the z variable is loaded and the loadAssetsInfo() has run successfully  \n
 * Then if it is able to find the file in the archive then it will return the temporary file path if is doesn't find it or can't write it then it returns NULL
 * @param fileInDarw the path to the assets file in the archive
 * @return returns the temporary file path and the fileName or if is doesn't find it or can't write it then it returns NULL
 */
std::pair<std::string, std::string> getAsset(const std::string& fileInDarw);


/**
 * This will first check if the z variable is loaded and the loadAssetsInfo() has run successfully  \n
 * Then it will return the temp directory for the OS this is running on
 * @return the string location of the temp directory but if it doesn't work then NULL is returned
 */
std::string getTempDirectory();

/**
 * This will first check if the z variable is loaded and the loadAssetsInfo() has run successfully  \n
 * After it will remove the current temp file in the OS temp directory
 * @param extractedFilePath the current temp file to remove
 * @return this will return true if deleted if not then it will return false
 */
bool removeCurrentTempFile(const std::pair<std::string, std::string>& file);

/**
 * More of an internal method that only works if the file has been initialized
 * @return returns false if z isn't loaded or if info wasn't loaded if it was then it returns true
 */
bool infoLoaded();

/**
 * Used to generate a sha256 checksum of a passed in string file location
 * @param filePath the path to the file that will be checksum
 * @return this returns the string sha256 checksum of the passed in file
 */
std::string sha256(const std::string& filePath);

/**
 * When done with the assets file use this to release memory and reset variables in this library
 * @return Will return true if released otherwise if something went wrong then false is returned
 */
bool releaseAssetsFile();

std::string generateTempFileName(std::string input);

/**
 * Holds the assets file in memory
 */
extern zip* z;

/**
 * turned true when assetsInfo loaded successfully
 */
extern bool assetsLoaded;

/**
 * The struct the file info is loaded into
 */
extern info darwInfo;

/**
 * This is the file path of the assets file
 */
extern std::string assetsFileName;

extern std::vector<std::string> tempFilesIn;

#endif //GAMEASSETSLOADER_LIBRARY_H
