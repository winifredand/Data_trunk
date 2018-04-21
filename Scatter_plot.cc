#include <iostream>
#include <math.h>
#include <stdio.h>

#include "TFile.h"
#include "TLegend.h"
#include "TH1F.h"
#include "TCanvas.h"
#include "TGraph.h"

int Scatter_plot()
{
    const Int_t N = 1000;
    Double_t x[N];
    Double_t y1[N];
    Double_t y2[N];
    Double_t y3[N];

    FILE *fp;
    fp = fopen("Guolu.txt", "r+");
    if (fp == NULL) 
        printf("Can not open this file, Exit.\n");

    Int_t i;
    for (i = 0; i < N; i ++)
    {
        fscanf(fp, "%lf %lf %lf %lf", &x[i], &y1[i], &y2[i], &y3[i]);
        printf("%lf\t%lf\t%lf\t%lf\n", x[i], y1[i], y2[i], y3[i]);
    }
    fclose(fp);

    TCanvas *c1 = new TCanvas("c1","The Graph trunk", 200, 10, 900, 700);
    c1->SetFillColor(0);
    //c1->SetGrid();

    gr = new TGraph(N,x,y1);
    gr->SetLineColor(4);
    gr->SetLineWidth(2);

    gr->SetMarkerColor(4);
    gr->SetMarkerStyle(21);
    gr->SetMarkerSize(1);

    gr->SetTitle("The Graph trunk");

   // cid = new char[8];
  //  sprintf(cid,"x/", i);
//    cid[7] = 0;


    gr->GetXaxis()->SetTitle("Time/s");
    gr->GetXaxis()->SetTitleOffset(1.);
    //gr->GetXaxis()->SetTextFont(32);
    gr->GetYaxis()->SetTitle("T2/℃");
    gr->GetXaxis()->CenterTitle();
    gr->GetYaxis()->CenterTitle();

    gr->SetMinimum(335.);
    gr->SetMaximum(350.);

    gr->Draw("ACP");  
  /*  

    gr1 = new TGraph(N,x,y2);
    gr1->SetLineColor(2);
    gr1->SetLineWidth(2);

    gr1->SetMarkerColor(2);
    gr1->SetMarkerStyle(24);
    gr1->SetMarkerSize(1);

    //gr1->BuildLegend();
    gr1->Draw("CP");

    TLegend *legend = new TLegend(.75,.80,.95,.95);
    legend->AddEntry(gr, "Background(WW)", "pl");
    legend->AddEntry(gr1, "Background(WW)", "pl");
    legend->SetFillColor(0);
    legend->SetBorderSize(1);
    //legend->SetLegendBorderSize(1);
    legend->Draw();
*/
    return 0;
}

