<?php

namespace Drupal\stanford_news_earth_matters\Routing;

use Drupal\Core\DependencyInjection\ContainerInjectionInterface;
use Drupal\Core\Entity\EntityTypeManager;
use Symfony\Component\DependencyInjection\ContainerInterface;
use Symfony\Component\Routing\Route;

/**
 * Class EarthMattersRoutes.
 *
 * @package Drupal\stanford_news_earth_matters\Routing
 */
class EarthMattersRoutes implements ContainerInjectionInterface {

  protected $entityTypeManager;

  /**
   * {@inheritdoc}
   */
  public function __construct(EntityTypeManager $entity_type_manager) {
    $this->entityTypeManager = $entity_type_manager;
  }

  /**
   * {@inheritdoc}
   */
  public static function create(ContainerInterface $container) {
    return new static(
      $container->get('entity_type.manager')
    );
  }

  /**
   * {@inheritdoc}
   */
  public function routes() {
    $routes = [];
    $num_terms = 0;

    $terms = $this->entityTypeManager->getStorage('taxonomy_term')
      ->loadMultiple();

    $path = '/earth-matters';
    $parameters = [];

    /** @var \Drupal\taxonomy\Entity\Term $term */
    foreach ($terms as $term) {
      if ($term->getVocabularyId() == 'earth_matters_topics') {
        $num_terms++;

        $path .= "/{term$num_terms}";
        $parameters["term$num_terms"] = ['type' => 'earth_matters_term'];

        $routes["stanford_news_earth_matters.{$num_terms}_terms"] = new Route(
          $path,
          [
            '_controller' => '\Drupal\stanford_news_earth_matters\Controller\EarthMattersController::page',
            '_title' => 'Earth Matters',
          ],
          ['_permission' => 'access content'],
          ['parameters' => $parameters]
        );

      }
    }

    return $routes;
  }

}
