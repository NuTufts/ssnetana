#include <iostream>
#include <string>

// larlitecv headers
// for source see: https://github.com/larbys/larlitecv
#include "Base/DataCoordinator.h"

// larlite


int main(int nargs, char** argv ) {

  std::cout << "SSNet Ana" << std::endl;

  // We open a larcv-format root file
  // From it we loop over the events and
  //   retrieve the image container for the ssnet output images for the event
  //   from the event container, we get the images for the event
  //   for each image, we analyze the contents, checking the output
  //
  //   to check the judgements, we have to determine the true answer for each pixel
  //   so in additition to the images, we have to retrieve the truth MC information
  //     about the event. We have the following truth information
  //     (1) mctrack and mcshower: objects which carry information
  //           about what particle traveled through the detector. each particle carries
  //           a unique ID number
  //     (2) instance image: tells us the ID number of the particle that deposited the
  //           energy into a given pixel in the image. we use it to correlate
  //           info in the images to the truth information about the particles

  // parse the arguments
  std::string ssnetfile  = argv[1];
  std::string mcinfofile = argv[2];
  std::string outfile    = argv[3];
  
  // First, lets load the files

  larlitecv::DataCoordinator dataco; // allows us to read entry-aligned larlite and larcv files
  dataco.add_inputfile( ssnetfile, "larcv" );
  dataco.add_inputfile( mcinfofile, "larlite" );
  dataco.initialize();


  int nentries = dataco.get_n_entries();
  std::cout << "Numebr of entries: " << nentries << std::endl;
  
  return 0;
}
