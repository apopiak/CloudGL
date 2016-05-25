#include "CreateSessionDialog.h"

#include <QDir>
#include <QFileDialog>
#include <QString>

CreateSessionDialog::CreateSessionDialog(QWidget * parent):
    QDialog(parent)
{
    m_ui.reset(new Ui::CreateSessionDialog());
    m_ui->setupUi(this);
}

const std::string & CreateSessionDialog::applicationPath() const
{
    return m_applicationPath;
}

const std::string & CreateSessionDialog::workingDirectory() const
{
    return m_workingDirectory;
}

void CreateSessionDialog::setApplicationPath(const std::string & path)
{
    m_applicationPath = path;
    m_ui->applicationPathLineEdit->setText(QString::fromStdString(path));
}

void CreateSessionDialog::setWorkingDirectory(const std::string & directory)
{
    m_workingDirectory = directory;
    m_ui->workingDirectoryLineEdit->setText(QString::fromStdString(directory));
}

void CreateSessionDialog::on_applicationPathButton_clicked(bool /*checked*/)
{
    QString fileName =
        QFileDialog::getOpenFileName(
            this,
            tr("Select the application"),
            QDir::currentPath());

    setApplicationPath(fileName.toStdString());
}

void CreateSessionDialog::on_workingDirectoryButton_clicked(bool /*checked*/)
{
    QString dirName =
        QFileDialog::getExistingDirectory(
            this,
            tr("Select the working dir"),
            QDir::currentPath());

    setWorkingDirectory(dirName.toStdString());
}

