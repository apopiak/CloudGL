#pragma once

#include <memory>
#include <string>

#include <QDialog>

#include "ui_CreateSessionDialog.h"

class CreateSessionDialog final:
    public QDialog
{
Q_OBJECT

public:
    CreateSessionDialog(QWidget * parent = nullptr);

    const std::string & applicationPath() const;
    const std::string & workingDirectory() const;

    void setApplicationPath(const std::string & path);
    void setWorkingDirectory(const std::string & directory);

private slots:
    void on_applicationPathButton_clicked(bool checked);
    void on_workingDirectoryButton_clicked(bool checked);

private:
    std::unique_ptr<Ui::CreateSessionDialog> m_ui;
    std::string m_applicationPath;
    std::string m_workingDirectory;
};

