<?php

namespace Drupal\stanford_news_earth_matters\PathProcessor;

use Drupal\Core\Entity\EntityTypeManager;
use Drupal\Core\PathProcessor\InboundPathProcessorInterface;
use Symfony\Component\HttpFoundation\Request;

class EarthMattersProcessor implements InboundPathProcessorInterface {

  protected $entityTypeManager;

  /**
   * EarthMattersProcessor constructor.
   *
   * @param \Drupal\Core\Entity\EntityTypeManager $entity_manager
   */
  public function __construct(EntityTypeManager $entity_manager) {
    $this->entityTypeManager = $entity_manager;
  }

  /**
   * Process paths to change term ids into clean url term names.
   *
   * @param string $path
   *   The original request path.
   * @param \Symfony\Component\HttpFoundation\Request $request
   *   Request object.
   *
   * @return string
   *   Converted path.
   */
  public function processInbound($path, Request $request) {
    if (strpos($path, '/earth-matters') !== 0) {
      return $path;
    }

    $parameters = $request->query->all();
    if (!empty($parameters['topic'])) {
      foreach ($parameters['topic'] as $tid) {
        $path .= "/$tid";
      }

      unset($parameters['topic']);
      $request->query->remove('topic', '');
    }

    $path_tids = array_map('trim', array_unique(explode('/', $path)));
    $terms = $this->entityTypeManager->getStorage('taxonomy_term')
      ->loadMultiple($path_tids);

    /** @var \Drupal\taxonomy\Entity\Term $term */
    foreach ($terms as $tid => $term) {
      $name = _stanford_news_earth_matters_clean_name($term->getName());
      $path = str_replace("/$tid", "/$name", $path);
    }

    return trim($path);
  }

}
