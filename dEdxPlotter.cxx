//____________________________________________________________________ 
//  
// $Id$ 
// Author: Pierre Lasorak <plasorak@pa-246-59.byodstaff.susx.ac.uk>
// Update: 2019-07-26 15:33:51+0100
// Copyright: 2019 (C) Pierre Lasorak
//
//
#ifndef __CINT__
// PUT HEADERS HERE
#include <vector>
#include <iostream>
#include <memory>
#include <algorithm>

#include "TTree.h"
#include "TChain.h"
#include "TFile.h"
#include "TProfile2D.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TCanvas.h"
#include "TPad.h"
#endif

// ------ VOLUME 50-60
// 50
const float xMinWorld = -2000;
const float xMaxWorld =  2000;
const float yMinWorld = -2000;
const float yMaxWorld =  2000;
const float zMinWorld = -2000;
const float zMaxWorld =  8000;

// ------ VOLUME 40-50
// 40
const float xMinDetEncl = -1000;
const float xMaxDetEncl =  1000;
const float yMinDetEncl = -1000;
const float yMaxDetEncl =  2000;
const float zMinDetEncl = -1000;
const float zMaxDetEncl = 15000;

// ------ VOLUME 30-40
// 37
const float xMinFullCryostat = -950;
const float xMaxFullCryostat =  950;
const float yMinFullCryostat = -845;
const float yMaxFullCryostat =  945;
const float zMinFullCryostat = -500;
const float zMaxFullCryostat = 6095;

const float Thickness = 193;
// 31
const float xMinBeamAndInsulationPosX = xMaxFullCryostat - Thickness;
const float xMaxBeamAndInsulationPosX = xMaxFullCryostat;
const float yMinBeamAndInsulationPosX = yMinFullCryostat;
const float yMaxBeamAndInsulationPosX = yMaxFullCryostat;
const float zMinBeamAndInsulationPosX = zMinFullCryostat;
const float zMaxBeamAndInsulationPosX = zMaxFullCryostat;

// 32
const float xMinBeamAndInsulationPosY = xMinFullCryostat;
const float xMaxBeamAndInsulationPosY = xMaxFullCryostat;
const float yMinBeamAndInsulationPosY = yMaxFullCryostat - Thickness;
const float yMaxBeamAndInsulationPosY = yMaxFullCryostat;
const float zMinBeamAndInsulationPosY = zMinFullCryostat;
const float zMaxBeamAndInsulationPosY = zMaxFullCryostat;

// 33
const float xMinBeamAndInsulationPosZ = xMinFullCryostat;
const float xMaxBeamAndInsulationPosZ = xMaxFullCryostat;
const float yMinBeamAndInsulationPosZ = yMinFullCryostat;
const float yMaxBeamAndInsulationPosZ = yMaxFullCryostat;
const float zMinBeamAndInsulationPosZ = zMaxFullCryostat - Thickness;
const float zMaxBeamAndInsulationPosZ = zMaxFullCryostat;

// 34
const float xMinBeamAndInsulationNegX = xMinFullCryostat;
const float xMaxBeamAndInsulationNegX = xMinFullCryostat + Thickness;
const float yMinBeamAndInsulationNegX = yMinFullCryostat;
const float yMaxBeamAndInsulationNegX = yMaxFullCryostat;
const float zMinBeamAndInsulationNegX = zMinFullCryostat;
const float zMaxBeamAndInsulationNegX = zMaxFullCryostat;

// 35
const float xMinBeamAndInsulationNegY = xMinFullCryostat;
const float xMaxBeamAndInsulationNegY = xMaxFullCryostat;
const float yMinBeamAndInsulationNegY = yMinFullCryostat;
const float yMaxBeamAndInsulationNegY = yMinFullCryostat + Thickness;
const float zMinBeamAndInsulationNegY = zMinFullCryostat;
const float zMaxBeamAndInsulationNegY = zMaxFullCryostat;

// 36
const float xMinBeamAndInsulationNegZ = xMinFullCryostat;
const float xMaxBeamAndInsulationNegZ = xMaxFullCryostat;
const float yMinBeamAndInsulationNegZ = yMinFullCryostat;
const float yMaxBeamAndInsulationNegZ = yMaxFullCryostat;
const float zMinBeamAndInsulationNegZ = zMinFullCryostat;
const float zMaxBeamAndInsulationNegZ = zMinFullCryostat + Thickness;

// ------ VOLUME 20-30
// 20
const float xMinLiquidArgonVolume = xMinFullCryostat + Thickness;
const float xMaxLiquidArgonVolume = xMaxFullCryostat - Thickness;
const float yMinLiquidArgonVolume = yMinFullCryostat + Thickness;
const float yMaxLiquidArgonVolume = yMaxFullCryostat - Thickness;
const float zMinLiquidArgonVolume = zMinFullCryostat + Thickness;
const float zMaxLiquidArgonVolume = zMaxFullCryostat - Thickness;

//21
const float xMinDSS =  xMinFullCryostat + Thickness;
const float xMaxDSS =  xMaxFullCryostat - Thickness;
const float yMinDSS =  yMaxFullCryostat - Thickness - 400;
const float yMaxDSS =  yMaxFullCryostat - Thickness;
const float zMinDSS =  zMinFullCryostat + Thickness;
const float zMaxDSS =  zMaxFullCryostat - Thickness;

// ------ VOLUME 10-20
// 10
const float xMinDriftVolume =  -10;
const float xMaxDriftVolume =  360;
const float yMinDriftVolume =  -10;
const float yMaxDriftVolume =  610;
const float zMinDriftVolume =  -10;
const float zMaxDriftVolume =  240;

// ------ VOLUME 0-10
// 2
const float xMinCathode = xMaxDriftVolume - 200;
const float xMaxCathode = xMaxDriftVolume;
const float yMinCathode = yMinDriftVolume;
const float yMaxCathode = yMaxDriftVolume;
const float zMinCathode = zMinDriftVolume;
const float zMaxCathode = zMaxDriftVolume;

// 1
const float xMinAnodeFrame = xMinDriftVolume;
const float xMaxAnodeFrame = xMinDriftVolume + 200;
const float yMinAnodeFrame = yMinDriftVolume;
const float yMaxAnodeFrame = yMaxDriftVolume;
const float zMinAnodeFrame = zMinDriftVolume;
const float zMaxAnodeFrame = zMaxDriftVolume;

// const float xMinFieldCage = xMinDriftVolume;
// const float xMaxFieldCage = xMaxDriftVolume;
// const float yMinFieldCage = yMinDriftVolume;
// const float yMaxFieldCage = yMaxDriftVolume;
// const float zMinFieldCage = zMinDriftVolume;
// const float zMaxFieldCage = zMaxDriftVolume;
// const float xMinFieldCage = xMinDriftVolume;
// const float xMaxFieldCage = xMaxDriftVolume;
// const float yMinFieldCage = yMinDriftVolume;
// const float yMaxFieldCage = yMaxDriftVolume;
// const float zMinFieldCage = zMinDriftVolume;
// const float zMaxFieldCage = zMaxDriftVolume;
// const float xMinFieldCage = xMinDriftVolume;
// const float xMaxFieldCage = xMaxDriftVolume;
// const float yMinFieldCage = yMinDriftVolume;
// const float yMaxFieldCage = yMaxDriftVolume;
// const float zMinFieldCage = zMinDriftVolume;
// const float zMaxFieldCage = zMaxDriftVolume;





std::vector<int> WhichVolume(float x,
                             float y,
                             float z) {
  std::vector <int> ret_vols;
  if (x > xMinAnodeFrame && x < xMaxAnodeFrame &&
      y > yMinAnodeFrame && y < yMaxAnodeFrame &&
      z > zMinAnodeFrame && z < zMaxAnodeFrame) {
    ret_vols.push_back(1);
  }
  if (x > xMinCathode && x < xMaxCathode &&
      y > yMinCathode && y < yMaxCathode &&
      z > zMinCathode && z < zMaxCathode) {
    ret_vols.push_back(2);
  }
  if (x > xMinDriftVolume && x < xMaxDriftVolume &&
      y > yMinDriftVolume && y < yMaxDriftVolume &&
      z > zMinDriftVolume && z < zMaxDriftVolume) {
    ret_vols.push_back(10);
  }
  if (x > xMinDSS && x < xMaxDSS &&
      y > yMinDSS && y < yMaxDSS &&
      z > zMinDSS && z < zMaxDSS) {
    ret_vols.push_back(20);
  }
  if (x > xMinLiquidArgonVolume && x < xMaxLiquidArgonVolume &&
      y > yMinLiquidArgonVolume && y < yMaxLiquidArgonVolume &&
      z > zMinLiquidArgonVolume && z < zMaxLiquidArgonVolume) {
    ret_vols.push_back(21);
  }
  if (x > xMinBeamAndInsulationNegZ && x < xMaxBeamAndInsulationNegZ &&
      y > yMinBeamAndInsulationNegZ && y < yMaxBeamAndInsulationNegZ &&
      z > zMinBeamAndInsulationNegZ && z < zMaxBeamAndInsulationNegZ) {
    ret_vols.push_back(31);
  }
  if (x > xMinBeamAndInsulationPosZ && x < xMaxBeamAndInsulationPosZ &&
      y > yMinBeamAndInsulationPosZ && y < yMaxBeamAndInsulationPosZ &&
      z > zMinBeamAndInsulationPosZ && z < zMaxBeamAndInsulationPosZ) {
    ret_vols.push_back(32);
  }
  if (x > xMinBeamAndInsulationNegY && x < xMaxBeamAndInsulationNegY &&
      y > yMinBeamAndInsulationNegY && y < yMaxBeamAndInsulationNegY &&
      z > zMinBeamAndInsulationNegY && z < zMaxBeamAndInsulationNegY) {
    ret_vols.push_back(33);                                                               
  }
  if (x > xMinBeamAndInsulationPosY && x < xMaxBeamAndInsulationPosY &&
      y > yMinBeamAndInsulationPosY && y < yMaxBeamAndInsulationPosY &&
      z > zMinBeamAndInsulationPosY && z < zMaxBeamAndInsulationPosY) {
    ret_vols.push_back(34);
  }
  if (x > xMinBeamAndInsulationNegX && x < xMaxBeamAndInsulationNegX &&
      y > yMinBeamAndInsulationNegX && y < yMaxBeamAndInsulationNegX &&
      z > zMinBeamAndInsulationNegX && z < zMaxBeamAndInsulationNegX) {
    ret_vols.push_back(35);                                                             
  }
  if (x > xMinBeamAndInsulationPosX && x < xMaxBeamAndInsulationPosX &&
      y > yMinBeamAndInsulationPosX && y < yMaxBeamAndInsulationPosX &&
      z > zMinBeamAndInsulationPosX && z < zMaxBeamAndInsulationPosX) {
    ret_vols.push_back(36);
  }
  if (x > xMinFullCryostat  && x < xMaxFullCryostat  &&
      y > yMinFullCryostat  && y < yMaxFullCryostat  &&
      z > zMinFullCryostat  && z < zMaxFullCryostat ) {
    ret_vols.push_back(37);
  }
  if (x > xMinDetEncl && x < xMaxDetEncl &&
      y > yMinDetEncl && y < yMaxDetEncl &&
      z > zMinDetEncl && z < zMaxDetEncl) {
    ret_vols.push_back(40);
  }
  if (x > xMinWorld && x < xMaxWorld &&
      y > yMinWorld && y < yMaxWorld &&
      z > zMinWorld && z < zMaxWorld) {
    ret_vols.push_back(50);
  }
  return ret_vols;
}

struct PlotSet {
  PlotSet(std::string name,
          int nBinX, float minX, float maxX,
          int nBinY, float minY, float maxY,
          int nBinZ, float minZ, float maxZ) {
    name_ = name;
    dEdx_xy_ = std::make_unique<TProfile2D>((name+"_xy_dedx").c_str(),
                                            (name+";X [mm];Y [mm]; dEdx [GeV/mm]").c_str(),
                                            nBinX, minX, maxX,
                                            nBinY, minY, maxY);
    dEdx_zy_ = std::make_unique<TProfile2D>((name+"_zy_dedx").c_str(),
                                            (name+";Z [mm];Y [mm]; dEdx [GeV/mm]").c_str(),
                                            nBinZ, minZ, maxZ,
                                            nBinY, minY, maxY);
    dEdx_E_ = std::make_unique<TH2D>((name+"_dedx_e").c_str(),
                                     (name+";E [GeV]; dEdx [GeV/mm]").c_str(),
                                     100, 99990, 100000,
                                     100, 0, 0.01);
  }

  void Fill(float x, float y, float z, float dedx, float e) {
    dEdx_vec_.push_back(dedx);
    dEdx_xy_->Fill(x,y,dedx);
    dEdx_zy_->Fill(z,y,dedx);
    dEdx_E_ ->Fill(e,dedx);
  }

  void Print(TCanvas& c, std::string name) {
    if (dEdx_vec_.size() == 0) {
      std::cout << name_ << " doesn't have any data!\n";
      return;
    }
    float max = *std::max_element(dEdx_vec_.begin(), dEdx_vec_.end());

    dEdx_ = std::make_unique<TH1D>((name_+"dedx").c_str(),(name_+";dEdx [GeV/mm];entries").c_str(),
                                   dEdx_vec_.size()/1000, 0, max);
    
    for (auto const& it: dEdx_vec_) {
      dEdx_->Fill(it);
    }
    std::cout << name_ << "\n";

    gPad->SetLogy(0);
    gPad->SetLogx(0);
    dEdx_E_->SetStats(0);
    dEdx_E_->Draw("COLZ");
    c.Print(name.c_str());
    dEdx_zy_->SetStats(0);
    dEdx_zy_->Draw("COLZ");
    c.Print(name.c_str());
    dEdx_xy_->SetStats(0);
    dEdx_xy_->Draw("COLZ");
    c.Print(name.c_str());
    gPad->SetLogy(1);
    gPad->SetLogx(1);
    dEdx_->SetStats(0);
    dEdx_->Draw();
    c.Print(name.c_str());
  }
  
  ~PlotSet() {
    dEdx_vec_.clear();
  }
  
private:
  std::vector<float> dEdx_vec_;
  std::string name_;
  std::unique_ptr<TH1D>       dEdx_   ;
  std::unique_ptr<TProfile2D> dEdx_xy_;
  std::unique_ptr<TProfile2D> dEdx_zy_;
  std::unique_ptr<TH2D>       dEdx_E_;
};
  
int dEdxPlotter() {
  // DEFINE YOUR MAIN FUNCTION HERE
  TChain tree("largeant/dEdx","READ");
  for (int i=0; i<28; ++i) {
    tree.Add(Form("g4_hist_%d.root",i)); 
  }
  
  std::vector<float> *fStartX   = nullptr;
  std::vector<float> *fStartY   = nullptr;
  std::vector<float> *fStartZ   = nullptr;
  std::vector<float> *fStartT   = nullptr;
  std::vector<float> *fStartE   = nullptr;
  std::vector<float> *fEndX     = nullptr;
  std::vector<float> *fEndY     = nullptr;
  std::vector<float> *fEndZ     = nullptr;
  std::vector<float> *fEndT     = nullptr;
  std::vector<float> *fEndE     = nullptr;
  std::vector<int>   *fPDG      = nullptr;
  std::vector<bool>  *fLastStep = nullptr;
  
  tree.SetBranchAddress("StartX"  , &fStartX  );
  tree.SetBranchAddress("StartY"  , &fStartY  );
  tree.SetBranchAddress("StartZ"  , &fStartZ  );
  tree.SetBranchAddress("StartT"  , &fStartT  );
  tree.SetBranchAddress("StartE"  , &fStartE  );
  tree.SetBranchAddress("EndX"    , &fEndX    );
  tree.SetBranchAddress("EndY"    , &fEndY    );
  tree.SetBranchAddress("EndZ"    , &fEndZ    );
  tree.SetBranchAddress("EndT"    , &fEndT    );
  tree.SetBranchAddress("EndE"    , &fEndE    );
  tree.SetBranchAddress("PDG"     , &fPDG     );
  tree.SetBranchAddress("LastStep", &fLastStep);
  int nBins = 200;
  PlotSet World_plot                ("World"                , nBins, xMinWorld                , xMaxWorld                , nBins, yMinWorld                , yMaxWorld                , nBins, zMinWorld                , zMaxWorld                );
  PlotSet DetEncl_plot              ("DetEncl"              , nBins, xMinDetEncl              , xMaxDetEncl              , nBins, yMinDetEncl              , yMaxDetEncl              , nBins, zMinDetEncl              , zMaxDetEncl              );
  PlotSet FullCryostat_plot         ("FullCryostat"         , nBins, xMinFullCryostat         , xMaxFullCryostat         , nBins, yMinFullCryostat         , yMaxFullCryostat         , nBins, zMinFullCryostat         , zMaxFullCryostat         );
  PlotSet BeamAndInsulationPosX_plot("BeamAndInsulationPosX", nBins, xMinBeamAndInsulationPosX, xMaxBeamAndInsulationPosX, nBins, yMinBeamAndInsulationPosX, yMaxBeamAndInsulationPosX, nBins, zMinBeamAndInsulationPosX, zMaxBeamAndInsulationPosX);
  PlotSet BeamAndInsulationPosY_plot("BeamAndInsulationPosY", nBins, xMinBeamAndInsulationPosY, xMaxBeamAndInsulationPosY, nBins, yMinBeamAndInsulationPosY, yMaxBeamAndInsulationPosY, nBins, zMinBeamAndInsulationPosY, zMaxBeamAndInsulationPosY);
  PlotSet BeamAndInsulationPosZ_plot("BeamAndInsulationPosZ", nBins, xMinBeamAndInsulationPosZ, xMaxBeamAndInsulationPosZ, nBins, yMinBeamAndInsulationPosZ, yMaxBeamAndInsulationPosZ, nBins, zMinBeamAndInsulationPosZ, zMaxBeamAndInsulationPosZ);
  PlotSet BeamAndInsulationNegX_plot("BeamAndInsulationNegX", nBins, xMinBeamAndInsulationNegX, xMaxBeamAndInsulationNegX, nBins, yMinBeamAndInsulationNegX, yMaxBeamAndInsulationNegX, nBins, zMinBeamAndInsulationNegX, zMaxBeamAndInsulationNegX);
  PlotSet BeamAndInsulationNegY_plot("BeamAndInsulationNegY", nBins, xMinBeamAndInsulationNegY, xMaxBeamAndInsulationNegY, nBins, yMinBeamAndInsulationNegY, yMaxBeamAndInsulationNegY, nBins, zMinBeamAndInsulationNegY, zMaxBeamAndInsulationNegY);
  PlotSet BeamAndInsulationNegZ_plot("BeamAndInsulationNegZ", nBins, xMinBeamAndInsulationNegZ, xMaxBeamAndInsulationNegZ, nBins, yMinBeamAndInsulationNegZ, yMaxBeamAndInsulationNegZ, nBins, zMinBeamAndInsulationNegZ, zMaxBeamAndInsulationNegZ);
  PlotSet LiquidArgonVolume_plot    ("LiquidArgonVolume"    , nBins, xMinLiquidArgonVolume    , xMaxLiquidArgonVolume    , nBins, yMinLiquidArgonVolume    , yMaxLiquidArgonVolume    , nBins, zMinLiquidArgonVolume    , zMaxLiquidArgonVolume    );
  PlotSet DSS_plot                  ("DSS"                  , nBins, xMinDSS                  , xMaxDSS                  , nBins, yMinDSS                  , yMaxDSS                  , nBins, zMinDSS                  , zMaxDSS                  );
  PlotSet DriftVolume_plot          ("DriftVolume"          , nBins, xMinDriftVolume          , xMaxDriftVolume          , nBins, yMinDriftVolume          , yMaxDriftVolume          , nBins, zMinDriftVolume          , zMaxDriftVolume          );
  PlotSet Cathode_plot              ("Cathode"              , nBins, xMinCathode              , xMaxCathode              , nBins, yMinCathode              , yMaxCathode              , nBins, zMinCathode              , zMaxCathode              );
  PlotSet AnodeFrame_plot           ("AnodeFrame"           , nBins, xMinAnodeFrame           , xMaxAnodeFrame           , nBins, yMinAnodeFrame           , yMaxAnodeFrame           , nBins, zMinAnodeFrame           , zMaxAnodeFrame           );

  for (int iEntry=0; iEntry<tree.GetEntries(); ++iEntry) {
    tree.GetEntry(iEntry);
    for(size_t iStep=0; iStep<fStartX->size(); ++iStep) {
      if (fLastStep->at(iStep) || fPDG->at(iStep) != 13)
        continue;
      
      float x = 0.5 * (fStartX->at(iStep) + fEndX->at(iStep));
      float y = 0.5 * (fStartY->at(iStep) + fEndY->at(iStep));
      float z = 0.5 * (fStartZ->at(iStep) + fEndZ->at(iStep));

      
      float d = sqrt(pow(fEndX->at(iStep) - fStartX->at(iStep),2) +
                     pow(fEndY->at(iStep) - fStartY->at(iStep),2) +
                     pow(fEndZ->at(iStep) - fStartZ->at(iStep),2));
      if (d==0) continue;
      float e = - fEndE->at(iStep) + fStartE->at(iStep);
      float dedx = e / d;
      if(fStartE->at(iStep) < 500 || dedx > 100)
        continue;
      // AnodeFrame            ->  1;
      // Cathode               ->  2;
      // DriftVolume           -> 10;
      // DSS                   -> 20;
      // LiquidArgonVolume     -> 21;
      // BeamAndInsulationNegZ -> 31;
      // BeamAndInsulationPosZ -> 32;
      // BeamAndInsulationNegY -> 33;
      // BeamAndInsulationPosY -> 34;
      // BeamAndInsulationNegX -> 35;
      // BeamAndInsulationPosX -> 36;
      // FullCryostat          -> 37;
      // DetEncl               -> 40;
      // World                 -> 50;

      for (auto const& it: WhichVolume(x,y,z)) {
        switch (it){
        case 1: {
          AnodeFrame_plot.Fill(x,y,z,dedx, fStartE->at(iStep));
          break;
        }
        case 2: {
          Cathode_plot.Fill(x,y,z,dedx, fStartE->at(iStep));
          break;
        }
        case 10:{
          DriftVolume_plot.Fill(x,y,z,dedx, fStartE->at(iStep));
          break;
        }
        case 20:{
          DSS_plot.Fill(x,y,z,dedx, fStartE->at(iStep));
          break;
        }
        case 21:{
          LiquidArgonVolume_plot.Fill(x,y,z,dedx, fStartE->at(iStep));
          break;
        }
        case 31:{
          BeamAndInsulationNegZ_plot.Fill(x,y,z,dedx, fStartE->at(iStep));
          break;
        }
        case 32:{
          BeamAndInsulationPosZ_plot.Fill(x,y,z,dedx, fStartE->at(iStep));
          break;
        }
        case 33:{
          BeamAndInsulationNegY_plot.Fill(x,y,z,dedx, fStartE->at(iStep));
          break;
        }
        case 34:{
          BeamAndInsulationPosY_plot.Fill(x,y,z,dedx, fStartE->at(iStep));
          break;
        }
        case 35:{
          BeamAndInsulationNegX_plot.Fill(x,y,z,dedx, fStartE->at(iStep));
          break;
        }
        case 36:{
          BeamAndInsulationPosX_plot.Fill(x,y,z,dedx, fStartE->at(iStep));
          break;
        }
        case 37:{
          FullCryostat_plot.Fill(x,y,z,dedx, fStartE->at(iStep));
          break;
        }
        case 40:{
          DetEncl_plot.Fill(x,y,z,dedx, fStartE->at(iStep));
          break;
        }
        case 50:{
          World_plot.Fill(x,y,z,dedx, fStartE->at(iStep));
          break;
        }
        }
      } 
    }
  }

  
  TCanvas c;
  c.Print("Profile.pdf[");
  World_plot                .Print(c,"Profile.pdf");
  DetEncl_plot              .Print(c,"Profile.pdf");
  FullCryostat_plot         .Print(c,"Profile.pdf");
  BeamAndInsulationPosX_plot.Print(c,"Profile.pdf");
  BeamAndInsulationPosY_plot.Print(c,"Profile.pdf");
  BeamAndInsulationPosZ_plot.Print(c,"Profile.pdf");
  BeamAndInsulationNegX_plot.Print(c,"Profile.pdf");
  BeamAndInsulationNegY_plot.Print(c,"Profile.pdf");
  BeamAndInsulationNegZ_plot.Print(c,"Profile.pdf");
  LiquidArgonVolume_plot    .Print(c,"Profile.pdf");
  DSS_plot                  .Print(c,"Profile.pdf");
  DriftVolume_plot          .Print(c,"Profile.pdf");
  Cathode_plot              .Print(c,"Profile.pdf");
  AnodeFrame_plot           .Print(c,"Profile.pdf");
  c.Print("Profile.pdf]");
  return 0;
}

#ifndef __CINT__
int main()
{
  return dEdxPlotter();
}
#endif

//____________________________________________________________________ 
//  
// EOF
//
