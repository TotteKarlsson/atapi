"""
Usage:
   python setup.py
"""
import site
import shutil
import os.path
import os
import glob

def getSitePackagesFolder():
    splist = site.getsitepackages()
    for s in splist:
        if s.find('site-packages') > 0:
            return s

def cleanFolder(path):
    print('Removing folder ' + path)
    shutil.rmtree(path, ignore_errors=True)

try:
    #=============================
    #First get sitepackages folder
    print ("Your Python SitePackage Folder " + str(getSitePackagesFolder()))
    atexplorerPackageName = 'atexplorer'
    destFolder = os.path.join(getSitePackagesFolder(), atexplorerPackageName)

    print('Installing ATExplorer package to folder: ' + destFolder)

    #clean destination folder
    print('Cleaning destination folder: ' + destFolder)
    cleanFolder(destFolder)

    #Figure what to copy
    currentFolder = os.path.dirname(os.path.abspath(__file__))
    print ("The Current Folder is: " + currentFolder)

    pyFilesFolder = os.path.join(currentFolder, "site-package")
    print ("Sources Folder: " + pyFilesFolder)

    pyFiles = glob.glob(os.path.join(pyFilesFolder, '*.*'))

    #Files that goes into site package folder
    allFiles = pyFiles
    if not os.path.exists(destFolder):
        os.makedirs(destFolder)

    #Copy root files
    for file in allFiles:
        print ('Copying: ' + file + '      ----->     ' + destFolder)
        shutil.copy(file, destFolder)

    print ('Done Copying')
except Exception as e:
    print ('There was a problem installing ATExplorer: ' + str(e))

