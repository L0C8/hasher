#include <wx/wx.h>

#include <random>
#include <string>

class HelloFrame : public wxFrame {
public:
    HelloFrame()
        : wxFrame(nullptr, wxID_ANY, "Hello wxWidgets", wxDefaultPosition, wxSize(400, 200)),
          rng_(std::random_device{}()),
          dist_(0, static_cast<int>(alphabet_.size()) - 1) {
        auto *panel = new wxPanel(this);

        label_ = new wxStaticText(panel, wxID_ANY, "Click the button", wxPoint(20, 20));

        auto *button = new wxButton(panel, wxID_ANY, "Generate", wxPoint(20, 60));
        button->Bind(wxEVT_BUTTON, &HelloFrame::OnGenerate, this);
    }

private:
    void OnGenerate(wxCommandEvent &) {
        label_->SetLabel(RandomString(6));
    }

    std::string RandomString(std::size_t length) {
        std::string result;
        result.reserve(length);
        for (std::size_t i = 0; i < length; ++i) {
            result.push_back(alphabet_[dist_(rng_)]);
        }
        return result;
    }

    wxStaticText *label_{nullptr};
    std::mt19937 rng_;
    std::uniform_int_distribution<int> dist_;
    static constexpr std::string_view alphabet_ = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
};

class HelloApp : public wxApp {
public:
    bool OnInit() override {
        auto *frame = new HelloFrame();
        frame->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(HelloApp);
