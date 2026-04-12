// Nythera Nightcode Preview

class ThemePreview {
  constructor(name, version) {
    this.name = name;
    this.version = version;
    this.languages = ["JavaScript", "Python", "HTML", "CSS"];
  }

  printInfo() {
    console.log(`Theme: ${this.name}`);
    console.log(`Version: ${this.version ?? "unknown"}`);
  }

  highlight(language) {
    if (this.languages.includes(language)) {
      return `Syntax highlighting enabled for ${language}`;
    }
    return "Language not supported";
  }

  async loadConfig(path = "./config.json") {
    try {
      const response = await fetch(path);
      const data = await response.json();
      return data?.settings ?? null;
    } catch (error) {
      console.error("Failed to load config:", error.message);
      return null;
    }
  }
}

const theme = new ThemePreview("Nythera Nightcode", 1.1);

theme.printInfo();

for (const lang of theme.languages) {
  console.log(theme.highlight(lang));
}
