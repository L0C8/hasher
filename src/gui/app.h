#pragma once

#include <wx/wx.h>

#include <random>
#include <string>

class HelloFrame : public wxFrame {
public:
    HelloFrame();

private:
    void OnGenerate(wxCommandEvent &);
    std::string RandomString(std::size_t length);

    wxStaticText *label_{nullptr};
    std::mt19937 rng_;
    std::uniform_int_distribution<int> dist_;
    inline static constexpr std::string_view alphabet_ =
        "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
};

class HelloApp : public wxApp {
public:
    bool OnInit() override;
};
