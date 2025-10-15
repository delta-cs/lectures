// Dark Mode Toggle Script
(function() {
  'use strict';

  // Get saved theme from localStorage or use system preference
  function getPreferredTheme() {
    const savedTheme = localStorage.getItem('theme');
    if (savedTheme) {
      return savedTheme;
    }
    
    // Check system preference
    if (window.matchMedia && window.matchMedia('(prefers-color-scheme: dark)').matches) {
      return 'dark';
    }
    
    return 'light';
  }

  // Set theme
  function setTheme(theme) {
    document.documentElement.setAttribute('data-theme', theme);
    localStorage.setItem('theme', theme);
    updateToggleButton(theme);
  }

  // Update toggle button icon
  function updateToggleButton(theme) {
    const button = document.querySelector('.dark-mode-toggle');
    if (button) {
      button.innerHTML = theme === 'dark' ? '☀️' : '🌙';
      button.setAttribute('aria-label', theme === 'dark' ? 'Přepnout na světlý režim' : 'Přepnout na tmavý režim');
    }
  }

  // Toggle theme
  function toggleTheme() {
    const currentTheme = document.documentElement.getAttribute('data-theme') || 'light';
    const newTheme = currentTheme === 'dark' ? 'light' : 'dark';
    setTheme(newTheme);
  }

  // Initialize theme immediately (before page load) to prevent flash
  const initialTheme = getPreferredTheme();
  document.documentElement.setAttribute('data-theme', initialTheme);

  // Wait for DOM to be ready
  if (document.readyState === 'loading') {
    document.addEventListener('DOMContentLoaded', initializeDarkMode);
  } else {
    initializeDarkMode();
  }

  function initializeDarkMode() {
    // Create toggle button
    const toggleButton = document.createElement('button');
    toggleButton.className = 'dark-mode-toggle';
    toggleButton.setAttribute('type', 'button');
    toggleButton.setAttribute('title', 'Přepnout tmavý/světlý režim');
    document.body.appendChild(toggleButton);

    // Set initial theme and button state
    setTheme(initialTheme);

    // Add click event listener
    toggleButton.addEventListener('click', toggleTheme);

    // Listen for system preference changes
    if (window.matchMedia) {
      window.matchMedia('(prefers-color-scheme: dark)').addEventListener('change', function(e) {
        // Only update if user hasn't set a manual preference
        if (!localStorage.getItem('theme')) {
          setTheme(e.matches ? 'dark' : 'light');
        }
      });
    }
  }
})();

